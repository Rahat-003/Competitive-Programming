#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> graph;
int n;

void bfs(int a){
map<int,int>lvl;

lvl[a]=0;
map<int,bool>vis;
vis[a] = true;
queue<int>q;
q.push(a);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++){
        int child = graph[u][i];
        if(!vis[child]){
            vis[child] = true;
            q.push(child);
            lvl[child] = lvl[u] + 1;
        }
    }
    }
    for(int i=1;i<n;i++)
        cout<<lvl[i]<<endl;
}

int main(){
   // freopen("10959.txt","r",stdin);
int t,c=0;
cin>>t;
while(t--){
        graph.clear();
    if(c>0) cout<<endl;
    c++;
    int e;    cin>>n>>e;
    while(e--){
        int a,b;    cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
bfs(0);
}


return 0;
}
