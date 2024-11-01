#include <bits/stdc++.h>
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;

#define mx 10002
vector<int> v[mx];

int par[mx],L[mx],dis[mx];

void dfs(int u,int a){
    vis[u] = 1;
    static int x  = 0;
    dis[u] = ++x;
    for(int i:v[u]){
        if(vis[i]){
            dis[u] = min(dis[u],
        }
    }


}


main(){
//read;
int n,m;
cin>>n>>m;
for(int i =0; i<m; i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
}





return 0;
}
