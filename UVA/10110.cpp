#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
/*
#define mx 66000
bool ar[mx];
vector<ll> prime;

void sieve(){
    prime.push_back(2);
    for(ll i = 3; i*i<=mx; i+=2){
        if(!ar[i]){
            for(ll j = i*i; j<mx; j+=2*i){
                ar[j] = 1;
            }
        }
    }
    for(ll i = 3; i<mx; i+=2)
        if(!ar[i])  prime.push_back(i);

}

ll numDiv(ll n){
    ll ans = 1;
    for(auto i:prime){
        if(i>n) break;
        if(n%i==0){
            ll cnt = 1;
            while(n%i==0){
                n/=i;
                cnt++;
            }
            ans*=cnt;
        }
    }
    if(n>1) ans*=2;
    return ans;
}

*/
int main(){
//sieve();

ll n;
while(1==scanf("%lld",&n)){
    if(!n)  break;
    bool fl = false;
    ll z = sqrt(n);
/*
    ll x = numDiv(n);
//       printf("%lld\n",x);

    if(x&1) fl = true;
    if(fl)  puts("yes");
    else puts("no");
*/
    if(z*z==n)  puts("yes");
    else puts("no");

}



return 0;
}
