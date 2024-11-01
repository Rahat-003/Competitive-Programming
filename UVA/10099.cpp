#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

vector<ppp> graph;
vector<int> ar;
vector<pp> par;
vector<vector<pp>> mp;

int n;
int f(int a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}

void k(){
  for(int i=0;i<graph.size();++i){
    int px = f(graph[i].second.first);
    int py = f(graph[i].second.second);
    int pz = graph[i].first;
    if(px!=py){
        mp[py].push_back(pp(pz,px));
        mp[px].push_back(pp(pz,py));
      ar[py] = px;
    }
  }
}

int bfs(int s,int d){
  vector<bool> vis;
  vis.assign(n+1,false);
  vis[s] = true;
  queue<int> q;
  par[s] = pp(-1,-1);
  q.push(s);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i=0;i<mp[u].size();++i){
      int child = mp[u][i].second;
      int cost = mp[u][i].first;
      if(!vis[child]){
        q.push(child);
        vis[child] = true;
        par[child] = pp(cost,u);
      }
      if(child==d)  break;
    }
  }
  int tmp = d;
  int min_cost = 1e7;
//  vector<int> v;
  while(par[tmp].second!=-1){
    int w = par[tmp].first;
    if(w<min_cost)  min_cost = w;
    tmp = par[tmp].second;
    if(tmp==-1) break;
  }
  vis.clear();
  return min_cost;
}

int main(){
  //freopen("print.txt","w",stdout);
int e;
int tc=0;
bool fl = false;
while(cin>>n>>e){
  if(!n && !e ) break;
  /*
  if(fl)  cout<<endl;
  fl=true;
  */
  tc++;
  for(int i=0;i<=n;++i)
    ar.push_back(i);

  mp.assign(n+1,vector<pp>());
  par.assign(n+1,pp(0,0));
  /*
  for(int i=0;i<par.size();++i)
    cout<<par[i].first<<" "<<par[i].second<<endl;
*/
  for(int i=0;i<e;i++){
  int a,b,c;
  cin>>a>>b>>c;
  graph.push_back(ppp(c,pp(a,b)));
  }
//  cout<<endl;
  sort(graph.begin(),graph.end(), greater<ppp> ());
 /* for(int i=0;i<graph.size();++i)
    cout<<graph[i].second.first<<" "<<graph[i].second.second<<" "<<graph[i].first<<endl;
  /**/
  k();
  int s,d,c;  cin>>s>>d>>c;
  int min_w = bfs(s,d);
  int with_G = min_w-1;
  int trip;
  if(c%with_G==0)
    trip = c/with_G;
  else trip = c/with_G + 1;

//  cout<<trip<<endl;
  printf("Scenario #%d\nMinimum Number of Trips = %d\n",tc,trip);
  graph.clear();  ar.clear(); par.clear();
  for(int i=0;i<mp.size();++i)
    mp[i].clear();

    cout<<endl;

}

return 0;
}
