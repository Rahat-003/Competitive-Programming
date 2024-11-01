    /**
    HackerRank : Primitive Problem
*/
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define mx 65536
typedef long long ll;


bool ar[mx];

vector<ll> prime,dv;

void sieve(){
    prime.push_back(2);
    for(ll i =3; i*i<=mx; i+=2){
        if(!ar[i]){
            for(ll j = i*i; j<mx; j+=2*i)
                ar[j] = true;
        }
    }
    for(ll i =3; i<mx; i+=2)
        if(!ar[i])  prime.push_back(i);
}

ll bMod(ll n , ll p, ll m){
    if(p==0)    return 1;
    if(p==1)    return n%m;
    if(p%2==0){
        ll x = bMod(n,p/2,m);
        return (x*x)%m;
    }
    else{
        ll y = bMod(n,p-1,m);
        return ( (n%m)*y )%m;
    }
}

bool check(ll n,ll m){
    for(auto i:dv){
        ll x = bMod(n,i,m);
        if(x==1)    return false;
    }
    return true;
}

ll f(ll n, ll &tot){
    ll phi = n-1, N = n;
    n-=1;
    tot = 1;
    for(auto i:prime){
        if(i*i>n)   break;

        if(n%i==0){
            tot*=(i-1);
            n/=i;
            dv.push_back(phi/i);
            while(n%i==0){
                tot*=i;
                n/=i;
            }
        }
    }
    if(n>1){
        dv.push_back(phi/n);
        tot*=(n-1);
    }

        for(ll i = 2; i<N; i++){
//        for(ll i = N-1; i>=2; i--){
    	bool kk = check(i,phi+1);
        if(kk){
            return i;
        }
    }

}


int main(){
sieve();
int t;  scanf("%d",&t);
ll n,m,p;
while(t--){
    scanf("%lld",&n);
    ll x;
    ll ans = f(n,x);

    printf("%lld\n",ans);


    dv.clear();
}




return 0;
}

