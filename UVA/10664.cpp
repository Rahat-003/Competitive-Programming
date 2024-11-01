#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
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
vector<int> v;
int ans = 0;
int dp[21][4003];
bool fn(int pos,int sum){
	if(pos==v.size()){
		return (sum*2==ans);
	}
	int &p = dp[pos][sum];
	if(p!=-1)	return p;
	bool a = fn(pos+1,sum+v[pos]);
	bool b = fn(pos+1,sum);
	return p = a||b;
}


int main(){
//	read;
int t,tc = 0;
scanf("%d",&t);
	cin.ignore();
while(t--){
	string s;
	getline(cin,s);
	istringstream iss(s);
	ans = 0;
	int a;
	while(iss>>a){
		ans+=a;
		v.push_back(a);
	}	
	
	if(ans&1)	puts("NO");
	else{
		memset(dp,-1,sizeof dp);
		
		bool fl = fn(0,0);
		if(fl)	puts("YES");
		else puts("NO");
	} 
	v.clear();
}

return 0;
}

