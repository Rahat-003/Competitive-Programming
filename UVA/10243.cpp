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
vector<int> v[1005];
int par[1005];
int n;
int dp[1005][3];

int f(int x,int y){
	if(v[x].size()==0)	return 1;
	if(dp[x][y]!=-1)	return dp[x][y];
	int sum = 0;
	for(int i = 0; i<v[x].size(); i++){
		int child = v[x][i];
		if(par[x]!=child){
			par[child] = x;
			if(y==0)	sum+=f(child,1);
			else sum+=min(f(child,0),f(child,1));
		}
	}
	dp[x][y] = sum+y;
	return sum+y;
}

int main(){
//	read;
int t,tc = 0;
while(1==scanf("%d",&n)){
	if(!n)	break;
	memset(dp,-1,sizeof dp);
	memset(par,0,sizeof par);
	for(int i = 1; i<=n; i++){
		int x;	scanf("%d",&x);
		for(int j = 0; j<x; j++){
			int y;	scanf("%d",&y);
			v[i].push_back(y);
		}
	}
	int ans = min(f(1,0),f(1,1));
	printf("%d\n",ans);
	for(int i = 0; i<1005; i++)	v[i].clear();
}



return 0;
}

