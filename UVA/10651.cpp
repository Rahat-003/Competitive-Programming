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

int dp[(1<<13)];
int check(int n,int i){
	return n&=(1<<i);
}
int Set(int n,int i){
	return n|=(1<<i);
}
int reset(int n,int i){
	return n&=~(1<<i);
}
int flag;

int f(int m){
	int cnt = 0;
	for(int i = 0; i<12; i++){
		if( check(m,i) && check(m,i+1) )	return -1;
		if(check(m,i))	cnt++;
	}
return cnt;	
}

int fn(int mask){
	int y = f(mask);
	if(y!=-1)	return y;
	if(dp[mask]!=-1)	return dp[mask];
	
	int ans = 12;
	for(int i = 0; i<12; i++){
		if( !check(mask,i) && check(mask,i+1) && check(mask,i+2) ){
			mask = Set(mask,i);		mask = reset(mask,i+1);		mask = reset(mask,i+2);
			ans = min(ans, fn(mask) );
			mask = reset(mask,i);	mask = Set(mask,i+1);		mask = Set(mask,i+2);
		}
		if( i>=2 && check(mask,i-2) && check(mask,i-1) && !check(mask,i) ){
			mask = Set(mask,i);		mask = reset(mask,i-1);		mask = reset(mask,i-2);
			ans = min(ans, fn(mask) );
			mask = reset(mask,i);	mask = Set(mask,i-1);		mask = Set(mask,i-2);
		}
	}
	return dp[mask] = ans;
}

int main(){
int t,tc = 0;
scanf("%d",&t);
cin.ignore();
while(t--){
	string s;	
	getline(cin,s);
	memset(dp,-1,sizeof dp);
	flag = 0;
	for(int i = 0; i<s.size(); i++)
		if(s[i]=='o')	flag = Set(flag,11-i);
	
	int ans = fn(flag);
	printf("%d\n",ans);
}

return 0;
}

