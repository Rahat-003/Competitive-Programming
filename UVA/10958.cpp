
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define mx (int)1e6+3
typedef long long ll;

bool ar[mx];
vector<ll> prime;

ll factor(ll n){
    ll ans = 1;
    for(auto i:prime){
            if(i>n) break;
        if(n%i==0){
            ll t = 1;
            while(n%i==0){
                t++;
                n/=i;
            }
            ans*=t;
        }
    }
    if(n>1) ans*=2;
    return ans;
}

void sieve(){
    prime.push_back(2);
    for(ll i = 3; i*i<=mx; i+=2){
        if(!ar[i]){
            for(ll j = i*i; j<mx; j+=2*i)
                ar[j] = true;
        }
    }
    for(ll i = 3; i<mx; i+=2)
        if(!ar[i])  prime.push_back(i);
}

int main(){
sieve();
ll tc = 0,m,n,p;
while(3==scanf("%lld %lld %lld",&m,&n,&p)){
    if(!m && !n && !p)  break;

    ll num = m*n*p*p;
    if(num<0)   num = abs(num);
    ll numberOfFactor = factor(num);
    ll ans = 2*numberOfFactor-1;
    printf("Case %lld: %lld\n",++tc,ans);
}

return 0;
}
