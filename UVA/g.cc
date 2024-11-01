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
int dp[10003][103];

//int coin[103]={5,97,233,31};

int coin[104];

const int inf  = 1e7;
int ans;
    int n = 4;

int bill(int w,int i){
    if(i==0 || w<0)    return inf;
    if(w==0)    return 0;
    if(dp[w][i]!=-1)    return dp[w][i];
    int x,y;
    x = 1+bill(w-coin[i-1],i);
    y = bill(w,i-1);
    dp[w][i]=min(x,y);
    return min(x,y);
}

int f(int w,int i){
    if(i==n)    return inf;
    if(w>=ans){
        return w;
    }
    if(dp[w][i]!=-1)    return dp[w][i];

    cout<<w<<" "<<i<<endl;

    int x,y;
    x = f(w+coin[i],i+1);
    y = f(w,i+1);
    dp[w][i] = min(x,y);
    return min(x,y);
}


int main(){
//read;
int t,tc = 0;
cin>>t;
//while( cin>>ans){
while(t--){
    cin>>ans;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>coin[i];
    }
    /*
    */
    memset(dp,-1,sizeof dp);
    int p = f(0,0);
    memset(dp,-1,sizeof dp);
    int q = bill(p,n);
//    cout<<p<<" "<<q<<" "<<ans<<endl;
    cout<<p<<" "<<q<<endl;
}



return 0;
}

