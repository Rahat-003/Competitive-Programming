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

int m,c;
vector<vector<int>> v;
int dp[220][25];

int fn(int w,int i){
	if(w>m)	return -(1<<30);
	if(i==c)	return w;
	if(dp[w][i]!=-1)	return dp[w][i];
	int ans = -1;
	for(int k = 0; k<v[i].size(); k++)
		ans = max(ans,fn(w+v[i][k],i+1));
	
	dp[w][i] = ans;
	return ans;
}


int main(){
int t,tc = 0;
scanf("%d",&t);
while(t--){
	scanf("%d %d",&m,&c);
	memset(dp,-1,sizeof dp);
	v = vector<vector<int>> (c);
	for(int i = 0; i<c; i++){
		int x;	scanf("%d",&x);
		v[i] = vector<int> (x);
		for(int j = 0; j<x; j++)
			scanf("%d",&v[i][j]);
	}
	int ans = fn(0,0);
	if(ans<=0)	puts("no solution");
	else printf("%d\n",ans);
}

return 0;
}

