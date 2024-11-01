#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d:",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
int w[][]={
    {10,10},
    {90,10}
};
int dp[(1<<5)+2],sz=2;

int Set(int x,int i){  return  x|=(1<<i);   }
bool check(int x,int i){
    return x&=(1<<i);
}
int call(int mask){
    if(mask==(1<<sz)-1) return 0;
    if(dp[mask]!=-1)    return dp[mask];
    int ans = 1e6;
    for(int i = 0; i<sz; i++){
        int price = w[i][i];
        if(check(mask,i)==0){
            for(int j = 0; j<sz; j++){
                if(i!=j && check(mask,j)==1){
                    price+=w[i][j];
                }
            }
            int x = price+call(Set(mask,i));
            ans = min(ans,x);
        }
    }
    return dp[mask]=ans;
}

int main(){
int t,tc = 0;
memset(dp,-1,sizeof dp);

cout<<call(0)<<endl;

return 0;
}

