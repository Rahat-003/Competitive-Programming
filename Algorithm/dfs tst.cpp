#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
vector<vector<int>>v(MAX);
bool vis[MAX];


void dfs(int s){
    vis[s]=true;
    cout<<s<<" ";
    for(int i=0;i<v[s].size();i++){
        int child=v[s][i];
        if(!vis[child]){
            vis[child]=true;
            dfs(child);
        }
    }

}

int main(){
int n;
cin>>n;
int e;
cin>>e;
while(e--){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
}
memset(vis,false,sizeof(vis));
dfs(1);


return 0;
}
