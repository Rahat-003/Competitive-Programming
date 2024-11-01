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
#define mx 10005
vector<ll> coin;
ll dp[mx][25];

ll f(ll w, ll i){
    if(!w)  return 1;
    if(i==0 || w<0) return 0;
    if(dp[w][i]!=-1)    return dp[w][i];
    ll x,y;
    x = f(w-coin[i-1],i);
    y = f(w,i-1);
    return dp[w][i]=x+y;
}

int main(){
int t,tc = 0;

for(ll i=1; i<=21; i++)
    coin.push_back(i*i*i);
memset(dp,-1,sizeof dp);
ll n;
while(1==scanf("%lld",&n)){
    printf("%lld\n",f(n,coin.size()));
}

return 0;
}

