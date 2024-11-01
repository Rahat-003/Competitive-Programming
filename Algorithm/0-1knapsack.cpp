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

int val[] = {10,12,8};
vector<int> wt = {2,5,1};
int dp[2000][20];

/*
3 27

10 7 2
12 1 5
8 1 1
*/

int fn(int w,int i){
	if(i==wt.size())	return 0;
//	if(w>7)	return 0;
	if(dp[w][i]!=-1)	return dp[w][i];
	int x = 0,y = 0;
//	cout<<w<<" "<<i<<" "<<dp[w][i]<<endl;
	if(w+wt[i]<=7)
	 x = val[i]+ fn(w+wt[i],i);
	 
	 y = fn(w,i+1);
	 
	return dp[w][i]=max(x,y);
}

int main(){

int t=7,tc = 0;
memset(dp,-1,sizeof dp);
cout<<fn(0,0)<<endl;


return 0;
}

