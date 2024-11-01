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
#define mx 1005
int n,w;
int val[mx],wt[mx];
int dp[mx][mx];

main(){
int t,tc = 0;

scanf("%d%d",&n,&w);

for(int i = 0; i<n; i++)   scanf("%d",val+i);
for(int i = 0; i<n; i++)   scanf("%d",&wt[i]);

for(int i = 0; i<=n; i++){
    for(int j = 0; j<=w; j++){
        if(i==0 || j==0)    dp[i][j] = 0;
        else if(wt[i-1]<=j) dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
        else dp[i][j] = dp[i-1][j];
    }
}
cout<<dp[n][w]<<endl;

return 0;
}
