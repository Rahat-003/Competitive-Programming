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
#define mx 1000000
ll ar[mx+2];
vector<ll> prime = {2};
void sieve(){
    for(ll i = 3; i*i<=mx; i+=2)    if(!ar[i])  for(ll j = i*i; j<mx; j+=2*i)   ar[j] = true;
    for(ll i = 3; i<mx; i+=2)   if(!ar[i])  prime.push_back(i);
}

ll fn(ll n){
    if(n<=3)    return 0;
    ll cnt = 0;
    for(ll i = 0; i<prime.size(); i++){
        if(prime[i]*prime[i]>n) break;
        for(ll j = prime[i]*prime[i]; j<=n; j*=prime[i]) cnt++;
    }
    return cnt;
}


int main(){
int t,tc = 0;
sieve();
scanf("%d",&t);
while(t--){
    ll a,b;
    scanf("%lld%lld",&a,&b);
    ll ans = fn(b) - fn(a-1);
    printf("%lld\n",ans);
}


return 0;
}

