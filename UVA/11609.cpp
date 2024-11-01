#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;

#define MOD (ll)1000000007

ll bigmod(ll n,ll p,ll m){
	if(p==0)	return 1;
	if(p==1)	return n%m;
	if(p%2==0){
		ll x = bigmod(n,p/2,m);
		return (x*x)%m;
	}
	else{
		ll y = bigmod(n,p-1,m);
		return (y*(n%m))%m;
	}
}


int main(){
int t;
scanf("%d",&t);
for(int i = 1; i<=t; i++){
	ll n;
	scanf("%lld",&n);
	
	printf("Case #%d: ",i);
	ll ans = bigmod(2,n-1,MOD);
	ans = ((n%MOD)*ans)%MOD;
	printf("%lld\n",ans);
}




return 0;
}

