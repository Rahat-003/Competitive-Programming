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

struct node{
	int r,c;
	node (int x,int y){
		r = x;	c = y;
	}
};
vector<node> v;
int dp[10][10];


int f(int x,int y){
	if(x==y)	return 0;
	if(dp[x][y]!=-1)	return dp[x][y];
	int ans = INT_MAX;
	
	for(int i = x; i<y; i++){
		int a,b,c;
		a = f(x,i);
		b = f(i+1,y);
		c = a+b+v[x].r*v[i].c*v[y].c;
		ans = min(ans,c);
	}
	dp[x][y] = ans;
	return ans;
}



int main(){
int t,tc = 0;

v.push_back(node(10,100));
v.push_back(node(100,5));
v.push_back(node(5,50));

memset(dp,-1,sizeof dp);

int ans = f(0,2);

cout<<ans<<endl;

return 0;
}

