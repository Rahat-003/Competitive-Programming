#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
typedef pair<int,pp> ipp;
vector<ipp> graph;
vector<int> ar;
vector<vector<int>> v;
vector<bool> vis;

void bfs(int a){
vis[a] = true;
queue<int> q;
q.push(a);
    while(!q.empty()){
      int u = q.front();
      q.pop();
      for(int i=0;i<v[u].size();++i){
        int child = v[u][i];
        if(!vis[child]){
          vis[child] = true;
          q.push(child);
        }
      }
    }
}
int port = 0;
int f(int a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}

int k(int p){
  int t = 0;
  for(int i=0;i<graph.size();++i){
    int px = f(graph[i].second.first);
    int py = f(graph[i].second.second);
    int pz = graph[i].first;
    if(px != py){

      if(pz>=p)   port+=1;

      else  t+=pz;

      ar[py] = px;
      vis[px] = true;
      vis[py] = true;
    }
  }
  return t;
}

int main(){
 freopen("11733.txt","w",stdout);
int t;  cin>>t;
for(int tc=1;tc<=t;tc++){
  port = 0;
  int p;
  int n,e;  cin>>n>>e>>p;
  vis.assign(n+1,false);
  v.assign(n+1,vector<int>());
  for(int i=0;i<=n;i++){
    ar.push_back(i);
  }
  int cost = 0 ;
  for(int i=0;i<e;i++){
    int a,b,c;
    cin>>a>>b>>c;
    graph.push_back(ipp(c,pp(a,b)));
    v[a].push_back(b);
    v[b].push_back(a);
  }
  sort(graph.begin(),graph.end());

  for(int i=1;i<vis.size();++i){
    if(!vis[i]){
      bfs(i);
      port++;
    }
  }
  cost = k(p);

  if(port>=n) port = n;

  printf("Case #%d: %d %d\n",tc,p*port+cost,port);
  graph.clear();
  ar.clear();
  vis.clear();
  for(int i=0;i<v.size();++i)
    v[i].clear();
}

return 0;
}
