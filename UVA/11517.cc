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
int coin[104];

const int inf  = 1e6;
int ans;
int n;

int bill(int w,int i){
    if(w==ans)    return 0;
    if(i==n || w>ans)    return inf;
    if(dp[w][i]!=-1)    return dp[w][i];
//	cout<<"bal\n";
    int x,y;
    x = 1+bill(w+coin[i],i+1);
    y = bill(w,i+1);
//    cout<<w<<" "<<i<<endl;
    dp[w][i]=min(x,y);
    return min(x,y);
}

int f(int w,int i){
	if(w<ans && i==n)	return inf;
   
    if(w>=ans){
//    	puts("bal");
        return w;
    }
    if(dp[w][i]!=-1)    return dp[w][i];
    int x,y;
    x = f(w+coin[i],i+1);
    y = f(w,i+1);
    dp[w][i] = min(x,y);
    return min(x,y);
}


int main(){
int t,tc = 0;
scanf("%d",&t);
while(t--){
	scanf("%d %d",&ans,&n);
    
    for(int i = 0; i<n; i++){
        scanf("%d",&coin[i]);
    }

    memset(dp,-1,sizeof dp);
    int p = f(0,0);
    memset(dp,-1,sizeof dp);
    int q = 0;
    ans = p;
	q = bill(0,0);
    printf("%d %d\n",p,q);
}



return 0;
}


