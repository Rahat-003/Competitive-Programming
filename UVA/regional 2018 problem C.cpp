#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case -: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

#define mx 1000002
bool ar[mx];
vector<ll> prime = {2};
const ll M = 1e7+7;

void sieve(){
	for(ll i = 3; i*i<=mx; i+=2)	if(!ar[i])	for(ll j = i*i; j<mx; j+=2*i)	ar[j] = 1;
	for(ll i = 3; i<mx; i+=2)	if(!ar[i])	prime.push_back(i);
}

ll fn(ll n,ll x){
	ll ans = 0;
	for(ll i = x; i<=n; i*=x)	ans+=n/i;
	return ans;
}

int main(){

ll n,tc = 0;
sieve();
while(1==scanf("%lld",&n)){
	if(!n)	break;
	ll ans = 1;

	for(ll i = 0; i<prime.size(); i++){
		if(prime[i]>n)	break;
		ll x = fn(n,prime[i]);
		x+=1;
		x = ((x*(x+1))/2)%M;
		ans = (ans*x)%M;
	}
	printf("%lld\n",ans);
}



return 0;
}

