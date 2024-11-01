/***********************
    LIS DP = O(n*n)
************************/
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
#define mx 5005
int ar[mx],dp[mx];


main(){
int t,tc = 0;

int n;
cin>>n;
double x;
for(int i = 0; i<n; i++)    cin>>ar[i];
int ans = 0;
for(int i = 0; i<n; i++){
    dp[i] = 1;
    for(int j = 0; j<i; j++){
        if(ar[i]>ar[j]) dp[i] = max(dp[i],dp[j]+1);
    }
    ans = max(ans,dp[i]);
}

cout<<ans<<endl;


return 0;
}

