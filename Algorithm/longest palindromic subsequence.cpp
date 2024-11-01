#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

int dp[30][30];

string s,t;

int fn(int i,int j){
	if(i>j)	return 0;
	if(i==j)	return dp[i][j] = 1;
	if(dp[i][j]!=-1)	return dp[i][j];
	
	if(s[i]==s[j])	return dp[i][j] = 2+fn(i+1,j-1);
	int ans = max(fn(i+1,j),fn(i,j-1));
	return dp[i][j] = ans;
}

int main(){
while(cin>>s){
memset(dp,-1,sizeof dp);
cout<<fn(0,s.size()-1)<<endl;
/*
for(int i = 0; i<s.size(); i++){
	for(int j = 0; j<s.size() ; j++) 	printf("%2d ",dp[i][j]);
	cout<<endl;
}
*/
}



return 0;
}

