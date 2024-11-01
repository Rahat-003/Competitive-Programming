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
ll a,b,c,k;
vector<ll> v;
ll dp[20][20][3];

ll fn(ll pos,ll cnt,ll fl){
	if(pos==v.size()){
		return cnt==k;
	}
	if(cnt>k)	return 0;
	if(dp[pos][cnt][fl]!=-1)	return dp[pos][cnt][fl];
	ll lmt = 9;
	if(fl)	lmt = v[pos];
	ll ans = 0;
	for(ll i = 0; i<=lmt; i++){
		ll x,y;		x = cnt,y = fl;
		if(i==c)	x++;
		if(fl && i<lmt)	y = 0;
		if(x<=k)ans+=fn(pos+1,x,y);
	}
	return dp[pos][cnt][fl] = ans;
}

ll solve(ll n){
	memset(dp,-1,sizeof dp);
	v.clear();
	while(n){
		v.push_back(n%10);
		n/=10;
	}
	reverse(v.begin(),v.end());
	ll ans = fn(0,0,1);
	return ans;
}

int main(){

scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
ll ans = solve(b) - solve(a-1);
printf("%lld\n",ans);

return 0;
}

