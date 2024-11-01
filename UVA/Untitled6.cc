#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
const ll P = 10000019ll;
#define mx 100002
bool ar[mx];
typedef pair<ll,ll> pp;
vector<ll> prime = {2};

void sieve(){
    for(ll i = 3;i*i<mx; i+=2)
        if(ar[i]==false)
            for(ll j = i*i; j<mx; j+=2*i)
            ar[j] = 1;
    for(ll i = 3; i<mx; i+=2)
        if(ar[i]==false)    prime.push_back(i);
}

ll bigmod(ll b,ll p,ll m){
    if(p==0)    return 1;
    if(p==1)    return b%m;
    ll x;
    if(p%2==0){
        x = bigmod(b,p/2,m)%m;
        return (x*x)%m;
    }
    return ((bigmod(b,p-1,m)%m)*b%m)%m;
}
ll fn(ll n,ll p){
    ll cnt = 0;
    for(ll i = p; i<=n; i*=p)   cnt+=n/i;
    return cnt;
}
vector<pp> v;

void solve(ll n){
    for(ll i = 0; i<prime.size(); i++){
        if(prime[i]>n)  break;
        ll x = fn(n,prime[i]);
        v.push_back(pp(prime[i],x));
    }
}

main(){


int t,tc = 0;
scanf("%d",&t);
sieve();

while(t--){
    ll n,b,ans = -1;
    scanf("%lld%lld",&n,&b);
    v.clear();
    solve(n);
    ll z = 1;
    for(ll i = 0; i<v.size(); i++){
        ll x = v[i].first,y = v[i].second;
        z = (z*bigmod(x,y/b,P))%P;
    }
    if(z==1)    ans = -1;
    else ans = z;
    case;
    printf("%lld\n",ans);
}


return 0;
}
