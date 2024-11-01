#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>g[100005];
bool vis[100005];
void dfs(int u,int par,int cnt){
if(!vis[u]){
    vis[u]=1;
    if(par){
            if(cnt%2==0)
    printf("%d %d\n",u,par);
    else
    printf("%d %d\n",par,u);
    }
}
    for(int i=0;i<g[u].size();i++)
        if(!vis[g[u][i]])
            dfs(g[u][i],u,cnt+1);
}

int main(){
int n,e,t,u,v;
scanf("%d",&t);
int k=0;
while(t--){

    scanf("%d",&n);
for(int i=0;i<=n;i++)
    g[i].clear();
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    printf("Case %d:\n",++k);
    fill(vis,vis+n+1,0);
dfs(1,0,0);
}



return 0;
}
