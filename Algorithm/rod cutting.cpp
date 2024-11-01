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

int ar[30],w[30];
int dp[30][30];

int fn(int L,int i){
	if(L<0)	return -1e6;
	if(L==0)	return 0;
	if(dp[L][i]!=-1)	return dp[L][i];
	int ans = 0;
//	cout<<L<<" "<<i<<endl;
	for(int k = 1; k<=L; k++){
		int x = w[k] + fn(L-k,k);
		ans = max(ans,x);
	}
	return dp[L][i] = ans;
}

int main(){
int t,tc = 0;

memset(dp,-1,sizeof dp);
int n;	scanf("%d",&n);
for(int i = 0; i<n; i++)	scanf("%d",&w[i+1]);

int ans = fn(n,0);
cout<<ans<<endl;

return 0;
}

