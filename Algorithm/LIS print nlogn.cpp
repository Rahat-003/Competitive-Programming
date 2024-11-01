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
typedef pair<int,int> pp;

int ar[mx],par[mx];
pp dp[mx];

int n;
vector<int> v;
int fn(int x){
    int id = lower_bound(dp,dp+n,pp(x,0)) - dp;
    return id;
}

main(){
int t,tc = 0;

scanf("%d",&n);

for(int i = 0; i<n; i++){
    scanf("%d",ar+i);
}

for(int i = 0; i<mx; i++){
    dp[i] = pp(INT_MAX,-1);
}

dp[0] = pp(-INT_MAX,-1);

int ans = 0,st;

for(int i = 0; i<n; i++){
    int x = ar[i];
    int id = fn(x);
    dp[id] = min(dp[id],pp(x,i));
    par[i] = dp[id-1].second;
    if(id>=ans){
        ans = id;
        st = dp[id].second;
    }
}

while(st!=-1){
    v.push_back(ar[st]);
    st = par[st];
}
reverse(v.begin(),v.end());
for(int i:v)
    cout<<i<<" ";
cout<<endl;


return 0;
}

