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

ll ar[23],sum;
int n,e;
int dp[(1<<20) + 5];
bool check(int mask,int i){
	return (mask&(1<<i));
}
int Set(int mask,int i){
	return mask|=(1<<i);
}
bool flag;
bool fn(int mask,ll p,ll cnt){
	if(mask==(1<<n)-1)	return true;
	if(flag)	return true;
		
	int &q = dp[mask];
	if(q!=-1)	return q;
	
	bool a = false;
	for(int i = 0; i<n; i++){
		if(!check(mask,i) && ar[i] + p<=e){
			ll x = p+ar[i],y = cnt;
			if(x==e)	x = 0,y++;
			if(y==4)	flag = true;
			a|=fn(Set(mask,i),x,y);
		}
	}
	return dp[mask] = a;
}

int main(){

read;

int t,tc = 0;
scanf("%d",&t);
while(t--){
	memset(dp,-1,sizeof dp);
//	for(int i = 0; i<=(1<<n)+2; i++)	dp[i] = -1;
	scanf("%d",&n);
	sum = 0;
	flag = false;
	for(int i = 0; i<n; i++){
		scanf("%lld",&ar[i]);
		sum+=ar[i];
	}
	if(sum%4!=0){
		puts("no");
		continue;
	}
	
	e = sum/4;

	bool fl = false;
	fl = fn(0,0,0);
	if(fl)	puts("yes");
	else puts("no");
}

return 0;
}

