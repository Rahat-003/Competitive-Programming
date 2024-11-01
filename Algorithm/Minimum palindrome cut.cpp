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
#define mx 1005
bool pal[mx][mx];
int dp[mx][mx];
string s;
const ll P = 31;
const ll M = 1e7+7;

//int cnt = 0;

int fn(int i,int j){
	if(i>j)	return s.size();
	if(i==j)	return 0;
	if(pal[i][j])	return 0;
	if(dp[i][j]!=-1)	return dp[i][j];
	int ans = s.size();
	
	for(int k = i; k<j; k++){
		if(pal[i][k]){
			int x = 1+fn(i,k) + fn(k+1,j);
			ans  = min(ans,x);
		}
//		cnt++;
	}
	
	return dp[i][j] = ans;
}


int A(){
	int cnt = 0;
	for(int i = 0; i<s.size(); i++){
		ll fwd = 0,bck = 0,t = 1;
		for(int j = i; j<s.size(); j++){
			fwd = (s[j]+fwd*P)%M;
			bck = (s[j]*t+bck)%M;
			t = (t*P)%M;
			if(fwd==bck)	{
				pal[i][j] = 1,	cnt++;
			}
		}
	}
	if(cnt==s.size())	return cnt-1;
	int ans = fn(0,s.size()-1);
	return ans;
}

int main(){
int t,tc = 0;
s = "aggaggbcb";
/*
for(int i = 0; i<1000; i++)	s.push_back('a');
for(int i = 500; i<=505; i++)	s[i] = 'a' + i-500+1;
//*/
for(int i = 0; i<s.size(); i++)	for(int j = 0; j<s.size(); j++)	dp[i][j] = -1;

/*
for(int i = 0; i<s.size(); i++){
	for(int j = 0; j<s.size(); j++)
		cout<<pal[i][j]<<" ";
		cout<<endl;
}
*/
cout<<A()<<endl;
//cout<<cnt<<" "<<s.size()<<endl;


return 0;
}

