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
string a,b;
int dp[50][50];

int edit(int i,int j){
	if(i==0)	return j;
	if(j==0)	return i;
	if(dp[i][j]!=-1)	return dp[i][j];
	return (a[i-1]==b[j-1])?edit(i-1,j-1): dp[i][j] = 1 + min(edit(i-1,j),min(edit(i-1,j-1),edit(i,j-1) ) ) ;
}

int main(){
int t,tc = 0;

while(cin>>a>>b){
	memset(dp,-1,sizeof dp);
	int ans = edit(a.size(),b.size());
	printf("%d\n",ans);
}

return 0;
}

