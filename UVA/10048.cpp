#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;
vector<ppp> graph;
vector<int> ar;
vector<vector<pp>> mp;
int n;
int f(int a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}
void k(){
  mp.assign(n+1,vector<pp>());
  for(int i=0;i<graph.size();++i){
    int px = f(graph[i].second.first);
    int py = f(graph[i].second.second);
    int pz = graph[i].first;
    if(px!=py){
      mp[px].push_back(pp(pz,py));
      mp[py].push_back(pp(pz,px));
      ar[py] = px;
    }
  }

}

int bfs(int s , int d){
  vector<bool> vis;
  vis.assign(n+1,false);
  vis[s] = true;
  vector<pp> par;
  par.assign(n+1,pp(0,0));
  par[s] = pp(-1,-1);
  queue<int> q;
  q.push(s);
    while(!q.empty()){
      int u = q.front();
      q.pop();
      for(int i=0;i<mp[u].size();++i){
        int child = mp[u][i].second;
        int cost = mp[u][i].first;
        if(!vis[child]){
          vis[child] = true;
          q.push(child);
          par[child] = pp(cost,u);

      }
      if(child==d)  break;
    }
  }
  if(!vis[d])
    return 0;
  else{
  int tmp = d;
  int _min = 0;
  while(par[tmp].second!=-1){

    int w = par[tmp].first;
    if(w>_min)  _min = w;

    tmp = par[tmp].second;
    if(tmp==-1) break;
  }
  return _min;
}
}
int main(){

int e,q;
int tc=0;
bool fl = false;
while(cin>>n>>e>>q){
  if(!n && !e && !q)  break;
  for(int i=0;i<=n;++i)
    ar.push_back(i);
  if(fl)  cout<<endl;
    fl = true;
    tc++;
  for(int i=0;i<e;++i){
    int a,b,c;
    cin>>a>>b>>c;
    graph.push_back(ppp(c,pp(a,b)));
  }
  sort(graph.begin(),graph.end());
  printf("Case #%d\n",tc);
  while(q--){
    int s,d;
    cin>>s>>d;
    k();
    int min_sound = bfs(s,d);
    if(min_sound) cout<<min_sound<<endl;
    else cout<<"no path\n";

    for(int i=0;i<mp.size();++i)
    mp[i].clear();
    ar.clear();
    for(int i=0;i<=n;++i)
    ar.push_back(i);
  }

//cout<<endl;
  graph.clear();  ar.clear();
}
return 0;
}
