#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d:",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
#define mx 2000

ll dp[mx+5];

const ll M = 100000007;
ll fn(ll n){
	if(!n || n==1)	return dp[n]=1;
	if(n==2)	return dp[n] = 2;
	if(dp[n]!=-1)	return dp[n]%M;
	ll sum = 0;
	for(ll i = 0; i<=n-1; i++){
		sum+=(fn(i)*fn(n-1-i))%M;
	}
	 dp[n] = sum%M;
	return dp[n];
}

int main(){

int t,tc = 0;
ll n;
memset(dp,-1,sizeof dp);
//scanf("%lld",&n);
fn(mx);

for(ll i = 0; i<=20; i++)	cout<<i<<" "<<dp[i]<<endl;

return 0;
}

