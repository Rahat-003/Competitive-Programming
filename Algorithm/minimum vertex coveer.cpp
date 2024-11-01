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
#define mx (int)1e5+3
int dp[mx][3];
int par[mx];
vector<vector<int>>v;
int f(int n,int x){
	if(v[n].size()==0)	return 0;
	if(dp[n][x]!=-1)	return dp[n][x];
	int sum = 0;
	for(int i = 0; i<v[n].size(); i++){
		int child = v[n][i];
		if(par[n]!=child){
			par[child] = n;
			if(x==0)	sum+=f(child,1);
			else sum+=min(f(child,0),f(child,1));
		}
	}
	return dp[n][x] = sum+x;
}

int main(){
int t,tc = 0;
scanf("%d",&t);
v.assign(t+1,vector<int>());
memset(dp,-1,sizeof dp);
memset(par,0,sizeof par);
for(int i = 0; i<t-1; i++){
	int a,b;	scanf("%d %d",&a,&b);
	v[a].push_back(b);	v[b].push_back(a);
}
int ans = min(f(1,0),f(1,1));
printf("%d\n",ans);
return 0;
}
