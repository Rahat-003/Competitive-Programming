#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;
#define Mx (1<<20)+3
#define mx Mx
bool ar[mx];

vector<ll> prime;

ll cPrime[Mx];

void sieve(){
    ar[0] = ar[1] = 1;
    prime.push_back(2);
    for(ll i = 3; i*i<=mx; i+=2){
        if(!ar[i]){
            for(ll j = i*i; j<mx; j+=2*i)
                ar[j] = 1;
        }
    }
    for(ll i = 3; i<mx; i+=2)
        if(!ar[i])  prime.push_back(i);
}

void composite(){
    for(ll i = 0; i<prime.size(); i++){
           ll  p = prime[i];
        if(p*p>=Mx) break;
        for(ll j = i; j<prime.size(); j++){
            ll x = prime[j]*p;
            if(x>=Mx)    break;
            cPrime[x] = 1;
        }
    }
}
int main(){
sieve();
composite();
	
ll n;
while(1==scanf("%lld",&n)){
        ll ans = 0;
    while(n--){
        ll a;   scanf("%lld",&a);
        ans+=cPrime[a];
    }
    printf("%lld\n",ans);
}


return 0;
}
