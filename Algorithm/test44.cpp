#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>graph;
int n;

void bfs(int s,int d){

queue<int>q;
vector<int>vis(n,0);
vector<int>par(n,-1);
vis[s]=1;
q.push(s);

while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];

        if(!vis[v]){
        //cout<<u<<" "<<v<<" ";
            vis[v]=1;
            par[v]=u;
            q.push(v);
        }
    }
}

vector<int>v;
while(d!=-1){
    v.push_back(d);
    d=par[d];
}
for(int i=v.size()-1;i>=0;i--)
    cout<<v[i]<<" ";
cout<<endl;
}

int main(){

int e;
cin>>n>>e;
graph.assign(n,vector<int>());
while(e--){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
}

int s,d;
cin>>s>>d;
bfs(s,d);
return 0;

}
