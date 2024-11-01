#include <bits/stdc++.h>
using namespace std;
int s,t;

vector<vector<int> >  graph,rgraph,v;
vector<int> par;
vector<bool> vis;
int n,e;

bool bfs(){
  par.assign(n,-1);
  vis.assign(n,false);
  vis[s] = true;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i = 0; i<v[u].size(); i++){
      int child = v[u][i];
      if(!vis[child] && rgraph[u][child]>0){
        par[child] = u;
        vis[child] = true;
        q.push(child);
      }
    }

  }
  return vis[t];
}

void dfs( /* arguments */int a) {
  /* code */
  vis[a] = true;
  for(int i = 0; i<v[a].size(); i++){
    int child = v[a][i];
    if(!vis[child] && rgraph[a][child]>0)
      dfs(child);
  }

}

void fordFulkerson(){
  int flow = 0;
  while (bfs()) {
    int x,y;
    int mx = 2e9;
    for(y = t; y!=s; y = par[y]){

      x = par[y];
      mx = min(mx,rgraph[x][y]);
    }
    for(y = t; y!=s; y = par[y]){
      x = par[y];
      // mx = min(mx,rGraph[x][y]);
      rgraph[x][y]-=mx;
      rgraph[y][x]+=mx;
    }
    flow+=mx;
    /* code */
  }

vis.assign(n,false);
dfs(s);
//cout<<"bal";

for(int i = 0 ;i<n; i++){
  for(int j = 0 ;j<n; j++){
//    cout<<"bal";
    if(!vis[j] && vis[i] && graph[i][j])
      cout<<i<<" "<<j<<endl;
  }

}

}

int main(int argc, char const *argv[]) {

cin>>n>>e;
v.assign(n,vector<int>());
graph.assign(n,vector<int>(n,0));
while (e--) {
  /* code */
  int a,b,c;
  cin>>a>>b>>c;
  v[a].push_back(b);
  v[b].push_back(a);
  graph[a][b] = c;
}
rgraph = graph;
cin>>s>>t;
fordFulkerson();


  return 0;
}
