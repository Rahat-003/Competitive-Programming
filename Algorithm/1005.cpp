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

ll ncr(ll n,ll r){
	ll dif = n-r;
	ll x = max(dif,r),	y = min(dif,r);
	ll a = 1;
	ll j = 2;
	for(ll i = x+1; i<=n; i++){
		a*=i;
		if(a%j==0 && j<=y){
			a/=j;
			++j;
		}
	}
	if(j>=y) return a;
	for(ll i = j; i<=y; i++)	a/=i;
	return a;
	
}

int main(){
int t,tc = 0;

scanf("%d",&t);
while(t--){
	ll n,k;
	scanf("%lld %lld",&n,&k);
	case;
	if(k>n){
		puts("0");	continue;
	}
	ll d = n-k;
	ll ans = ncr(n,d);
	for(ll i = 0; i<k; i++){
		ans*=(n-i);
	}
	printf("%lld\n",ans);
}



return 0;
}

