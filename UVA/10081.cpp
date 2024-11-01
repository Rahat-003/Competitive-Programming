#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
#define EPS 1e-12
double dp[102][10];
ll k,n;
double den;
double fn(ll pos,ll L){
    if(pos==n)  return 1;
    double &ans = dp[pos][L];
    if(ans!=-1) return ans;
    ans = 0;
    for(ll i = 0; i<=k; i++){
        if(pos==0)  L = i;
        ll x = abs(L-i);
        if(x<=1)    ans = (ans + fn(pos+1,i) );
    }
    if(pos==0)  return ans/den;

    return ans;
}

int  main(){
//    read;
ll t,tc = 0;
while(2==scanf("%lld%lld",&k,&n)){

    for(int i = 0; i<=n; i++)   for(int j = 0; j<10; j++)   dp[i][j] = -1;
    den = pow((double)k+1,n)/100.0;
    double tot = fn(0,0);

    printf("%.5f\n",tot);
}

return 0;
}

