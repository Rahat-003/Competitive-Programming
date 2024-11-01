/*
sample input

6 10
0 1  16
0 2 13
1 2 10
1 3 12
2 1 4
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4
0 5

output: 23

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph, rgraph,v;
int n,e;
vector<int> par;

bool bfs(int s,int d){

vector<bool> vis(n,false);
queue<int> q;
q.push(s);
vis[s] = true;
par[s] = -1;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i = 0; i<v[u].size(); i++){
      int child = v[u][i];
      if(!vis[child] && rgraph[u][child]>0 ){
        q.push(child);
        vis[child] = true;
        par[child] = u;
      }

    }
  }

  return (vis[d]==true);

}

int fordFulkerson(int s,int d){
  int flow = 0;

  while( bfs(s,d) ){
    int min_flow = 2e7;

    int y = d;

    while(true){
      int x = par[y];
//      cout<<x<<" "<<y<<endl;
      min_flow = min(min_flow,rgraph[x][y]);

      if(x==s) break;
      y = x;

    }
    y = d;
    while(true){
      int x = par[y];
//      int y = d;

      rgraph[x][y] -= min_flow;
      rgraph[y][x] += min_flow;
      if(x==s) break;
      y = x;
    }
//    cout<<min_flow<<" ";
    flow+= min_flow;
  }
 return flow;
}

int main(){

while(cin>>n>>e){

graph.assign(n,vector<int>(n,0));
v.assign(n,vector<int>());

par.assign(n,-1);

while(e--){
  int a,b,c;
  cin>>a>>b>>c;
  graph[a][b] = c;
  v[a].push_back(b);
  v[b].push_back(a);
}

rgraph = graph;

int s,d;
cin>>s>>d;
int flow = fordFulkerson(s,d);

cout<<flow<<endl;

}

return 0;
}
