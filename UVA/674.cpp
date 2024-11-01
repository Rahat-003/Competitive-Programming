#include <cstdio>
#include <iostream>
#include <memory.h>
#define case        printf("Case %d:",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
ll coin[]={1,5,10,25,50};
ll dp[10][8000];

ll f(int w,int i){
    if(i==0 || w<0)   return 0;
    if(!w)  return 1;
    if(dp[i][w]!=-1)    return dp[i][w];
//    if(w==coin[i-1])  return 1;   eta deya jabe na
    ll x,y;
    y=f(w,i-1);
    x=f(w-coin[i-1],i);
    dp[i][w]=x+y;
    return x+y;
}


int main(){
int t,tc = 0;
ll n;
    memset(dp,-1,sizeof dp);
    f(7489,5);
while(1==scanf("%lld",&n)){
    printf("%lld\n",f(n,5));
}


return 0;
}

