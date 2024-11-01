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
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

bool check(ll n,ll i){
    return n&(1ll<<i);
}

ll Set(ll n,ll i){
    return n|=(1ll<<i);
}
const ll P = 1000000007;
ll b,n;

ll dp[101][(1ll<<10)+2][10][2];

ll fn(ll pos,ll mask,ll last,bool st){

    if(pos==n)  return mask==(1ll<<b)-1;
    ll &ans = dp[pos][mask][last][st];
    if(ans!=-1) return ans;
    ans = 0;
    for(ll i = 0; i<b; i++){
        if(st && abs(last-i)!=1)    continue;

        ll S = st,M = mask;
        if(i)   S = true;
        if(S)   M = Set(mask,i);
        ans = (ans+fn(pos+1,M,i,S))%P;
    }
    return ans;
}

main(){
int t,tc = 0;

scanf("%d",&t);

while(t--){
    memset(dp,-1,sizeof dp);
    scanf("%lld%lld",&b,&n);
    ll ans = fn(0,0,0,0);
    printf("%lld\n",ans);
}


return 0;
}

