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
ll n,k,m;
ll ar[52];
ll dp[52][52][52];
ll fn(ll pos,ll bar,ll w){
	if(pos==n)	return bar==k;
	
	ll &ans = dp[pos][bar][w];
	if(ans!=-1)		return ans;
	ans = 0;

	ll b = bar,c = w;
	ar[pos+1] = 0;
	if(ar[pos+1]!=ar[pos])	c = 1,b++;
	else c++;
	if(c<=m)	ans+=fn(pos+1,b,c);
	b = bar,c = w;

		ar[pos+1] = 1;
		if(ar[pos+1]!=ar[pos])	c = 1,b++;
		else c++;
		if(c<=m)	ans+=fn(pos+1,b,c);
	
	return ans;
}

int main(){
int t,tc = 0;
read;
while(3==scanf("%lld%lld%lld",&n,&k,&m)){
	ll ans = 0;	
	memset(dp,-1,sizeof dp);
	ar[0] = 1;
	ar[n-1] = 0;
	ans = fn(1,1,1);
	printf("%lld\n",ans);
}

return 0;
}

