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
#define MX 1<<30

int mat[][10] = {
    { -1, 2, 5 },
    { 4, -2, 3 },
    {
        1, 2, 10,
    }
};

bool valid(int x,int y){
    if(x<0 || y<0 || x>2 || y>2)    return false;
    return true;
}
int dp[5][5];

int rock(int i,int j){
    if(!valid(i,j)) return 0;
    if(dp[i][j]!=-1)    return dp[i][j];
    int p = -MX;
    p=max(p,rock(i+1,j)+mat[i][j]);
    p=max(p,rock(i+1,j+1)+mat[i][j]);
    p=max(p,rock(i+1,j-1)+mat[i][j]);
    dp[i][j]=p;
    return p;
}



int main(){
int t,tc = 0;
memset(dp,-1,sizeof dp);
cout<<rock(0,0);



return 0;
}

