/*******************
LIS print O(N*N)
*******************/

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
int ar[mx],dp[mx],p[mx];
vector<int> v;

main(){
int t,tc = 0;

int n;
cin>>n;
double x;
for(int i = 0; i<n; i++)    cin>>ar[i],p[i] = -1;
int ans = 0;

p[0] = -1;
int st = 0;
for(int i = 0; i<n; i++){
    dp[i] = 1;
    for(int j = 0; j<i; j++){
        if(ar[i]>ar[j] && dp[j]+1>dp[i]){
            dp[i] = dp[j]+1;
            p[i] = j;
        }
    }
    if(ans<dp[i]){
        ans = dp[i];
        st = i;
    }
}
while(st!=-1){
    v.push_back(ar[st]);
    st = p[st];
}
for(int i = 0; i<n; i++)    cout<<p[i]<<" ";
cout<<endl;
cout<<ans<<endl;
reverse(v.begin(),v.end());
for(int i:v)    cout<<i<<" ";   cout<<endl;

return 0;
}

