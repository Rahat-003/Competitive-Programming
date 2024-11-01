#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
#define mx 100000010
int ar[mx/32+2];
vector<ll>prime = {2};

bool check(int n,int i){
    return n&(1<<i);
}
int Set(int n,int i){
    return n|(1<<i);
}

void sieve(){
    for(ll i = 3; i*i<=mx ; i+=2)if(!check(ar[i/32],i%32)) for(ll j = i*i; j<mx; j+=2*i)   ar[j/32] = Set(ar[j/32],j%32);
    for(ll i = 3; i<mx; i+=2)   if(!check(ar[i/32],i%32))  prime.push_back(i);
}

ll mulmod(ll a,ll b,ll c){
    ll x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

vector<ll> v = {2,3,5,7,11,13,17,19,23,29,31,37};

ll fn(ll b,ll p,ll m){
    if(p==0)    return 1;
    if(p==1)    return b%m;
    ll x;
    if(p%2==0){
        x = fn(b,p/2,m);
        return mulmod(x,x,m);
    }
    x = fn(b,p-1,m);
    return mulmod(x,b,m);
}


bool check(ll a,ll s,ll d,ll n){
    ll x = fn(a,d,n);
    if(x==1 || x==n-1)  return true;

    for(ll i = 1; i<s; i++){
        x = mulmod(x,x,n);
        if(x==n-1)  return true;
    }
    return false;
}

bool Miller(ll n){
    if(n<4) return n==2 || n==3;
    if(n%2==0)  return false;

    ll s = 0,d = n-1;
    while(d%2==0){
        s++;
        d/=2;
    }

    for(ll i:v){
    	if(n==i)	return true;
        ll a = i;
        if(!check(a,s,d,n)) return false;
    }
    return true;

}
bool isSq(ll n){
    ll s = sqrtl(n);
    return s*s==n;
}
typedef pair<ll,ll> pp;
vector<pp> pf;

void go(ll n){
    ll ans = 1;
    for(ll i:prime){
        if(i*i*i>n) break;
        ll cnt = 0;
        if(n%i==0){
        while(n%i==0){
            n/=i;
            cnt++;
        }
        ans*=cnt;
        pf.push_back({i,cnt});
        }
    }
    if(n==1)    return;
    if(Miller(n)){
        pf.push_back({n,1});
        return;
    }
    ll x = sqrtl(n);
    if(isSq(n)){
        pf.push_back({x,2});
        return;
    }
    ll id = lower_bound(prime.begin(),prime.end(),x) - prime.begin();
    if(id==prime.size())    id--;

    for(ll i = id,j = 0; i>=0; i--, j++){
        ll p = prime[i],q = prime[j];
        if(n%p==0){
            pf.push_back({n/p,1});
            pf.push_back({p,1});
            return;
        }
        if(n%q==0){
            pf.push_back({n/q,1});
            pf.push_back({q,1});
            return;
        }
    }

}

int main(){

int t,tc = 0;
sieve();
scanf("%d",&t);

while(t--){

ll n;
scanf("%lld",&n);
    go(n);
    printf("%lld = ",n);
    sort(pf.begin(),pf.end());
    for(int i = 0; i<pf.size(); i++){
        if(i)   printf(" * ");
        printf("%lld",pf[i].first);
        if(pf[i].second>1)  printf("^%lld",pf[i].second);
    }
    puts("");

    pf.clear();

}

return 0;
}


