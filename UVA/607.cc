#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d:",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

#ifndef mx
#define mx 1002
#endif
#define MX 1e15
ll w,ar[mx];
ll n,L,C;

ll go(){
	ll cnt = 0,sum = 0;
	bool fl = true;
	for(ll i = 0; i<n; i++){
		sum+=ar[i];

		if(sum==L){
			cnt++;
			sum = 0;
			if(i==n-1)
                fl = false;
		}
		else if(sum>L ){
			cnt++;
			sum = ar[i];
		}

	}
	cnt+=fl;
	return cnt;
}

ll dp[mx][mx];

ll fn(ll pos,ll rem){
/*
	if(pos==n && rem==w)    return 0;
	if(rem>w)   return MX;
*/
	if(pos==n){
        if(rem==w)  return 0;
        return MX;
	}
	ll &ans = dp[pos][rem];
	if(ans!=-1)		return ans;
	ans = MX;
	ll s = 0,t,x;

	for(ll i = pos; i<n; i++){
		s+=ar[i];
		t = L-s;
		if(s>L)	break;
		if(t==0)	x = 0;
		else if(t>=1 && t<=10)	x = -C;
		else x = (t-10)*(t-10);
		ans = min(ans,x+fn(i+1,rem+1));
	}
	return ans;
}

int main(){
int t,tc = 0;

while(1==scanf("%lld",&n)){
	if(n==0)	break;
	if(tc)	puts("");
	memset(dp, -1, sizeof dp);

	scanf("%lld%lld",&L,&C);
	for(ll i = 0; i<n; i++)	scanf("%lld",ar+i);
	w = go();
	case;	puts("");
	printf("Minimum number of lectures: %lld\n",w);
	printf("Total dissatisfaction index: %lld\n",fn(0,0));
}
/*
*/

return 0;
}
