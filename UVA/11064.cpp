#include <cstdio>
#include <vector>
using namespace std;

#define mx (int)47e3
bool ar[mx];
typedef long long ll;
vector<ll> prime;

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

ll phi(ll n){
    ll ans = n;
    ll cnt = 1;
    for(auto i:prime){
        if(i>n) break;
        if(n%i==0){
            ll x = 1;
            while(n%i==0){
                x++;
                n/=i;
            }
            ans-=ans/i;
            cnt*=x;
        }
    }
    if(n>1){
        ans-=ans/n;
        cnt*=2;
    }
    return ans+cnt-1;
}

int main(){

sieve();
ll n ;

while(1==scanf("%lld",&n)){
    ll ans = phi(n);
    printf("%lld\n",n-ans);
}





return 0;
}
