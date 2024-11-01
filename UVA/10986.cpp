#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
#define INF 1e7
vector<vector<pp>> v;
vector<int> dis;
vector<int> par;

void dijkstra(int s){

  priority_queue <pp,vector<pp>,greater<pp>> pq;
  pq.push(pp(0,s));
  dis[s] = 0;
  while(!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    for(int i=0;i<v[u].size();++i){
      int child = v[u][i].second;
      int w = v[u][i].first;

      if(dis[u]+w<dis[child]){
        dis[child] = dis[u]+w;
      pq.push(pp(dis[child],child));
      par[child] = u;
    }
  }
}
}

int main(){

int tc;
cin>>tc;
int cnt=0;
while(tc--){
  int n,e,s,d;
  cin>>n>>e>>s>>d;
  v.assign(n,vector<pp>());
  dis.assign(n,1e7);
  par.assign(n,0);
  cnt++;
  while(e--){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back(pp(c,b));
    v[b].push_back(pp(c,a));
  }
  dijkstra(s);
  printf("Case #%d: ",cnt);
  if(dis[d]==INF) cout<<"unreachable\n";
    else cout<<dis[d]<<endl;
  dis.clear();
  par.clear();
  for(int i=0;i<v.size();++i)
    v[i].clear();
}

return 0;
}
