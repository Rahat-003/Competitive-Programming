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
#define mx 1000001
#define mod (ll)1000000007
ll ar[mx+3];
ll fact[mx+3];

ll fn(ll a,ll b,ll c){
	if(b==0)	return 1;
	if(b==1)	return a%c;
	if(b%2==0){
		ll x = (fn(a,b/2,c))%c;
		return (x*x)%c;
	}
	ll x = fn(a,b-1,c)%c;
	return ((a%c)*(x%c))%c;
}

ll inv(ll a,ll m){
	return fn(a,m-2,m);
}

ll ncr(ll n, ll r){
	ll N = fact[n];
	return  ( (N*inv(fact[r],mod)%mod)*(inv(fact[n-r],mod)) )%mod;
}

int main(){
int t,tc = 0;
ll p = 1;
fact[0] = 1;

for(ll i = 1; i<=mx; i++){
	p = (p*i)%mod;
	fact[i] = p;
}
ll n,r;
while(2==scanf("%lld%lld",&n,&r)){
	printf("%lld\n",ncr(n,r));
}


return 0;
}

