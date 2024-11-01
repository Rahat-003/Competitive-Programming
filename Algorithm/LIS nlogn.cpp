/************************
    LIS (nlogn): elements are range from -MX to MX
***********************/

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
#define mx 100005
#define MX 10000000
int ar[mx],dp[mx];

int n;
int fn(int x){
    /// for longest non-decreasing subsequence use upper_bound
    int id = lower_bound(dp,dp+n,x)-dp;
    return id;
}

main(){
int t,tc = 0;
scanf("%d",&n);

for(int i = 0; i<n; i++){
    scanf("%d",ar+i);
    dp[i] = dp[i+1] = MX;
}
dp[0] = -MX;
int ans = 0;
for(int i = 0; i<n; i++){
    int x = ar[i];
    int id = fn(x);
    dp[id] = min(dp[id],x);
    ans = max(ans,id);
}

cout<<ans<<endl;

return 0;
}
