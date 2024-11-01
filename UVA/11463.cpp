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
#define mx 102
#define INF 10000000
int g[mx][mx];

int main(){
int t,tc = 0;
cin>>t;
while(t--){
    int n,e;
    cin>>n>>e;
    for(int i = 0; i<n; i++)
        fill(g[i],g[i]+n,INF);

    while(e--){
        int a,b;    cin>>a>>b;
        g[a][b] = 1;    g[b][a] = 1;
    }
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                g[j][j] = 0;
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    int ans = 0;
    int s,d,p;    cin>>s>>d;
    for(int i = 0; i<n; i++){
    if(g[s][i]!=INF && g[i][d]!=INF){
        /*if(g[s][i]+g[i][d]>ans){
            p = i;*/
        ans=max(ans,g[s][i]+g[i][d]);
        }
    }
    }
    case;
    printf(" %d\n",ans);

}



return 0;
}

