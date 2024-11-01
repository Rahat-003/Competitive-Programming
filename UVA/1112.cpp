#include <bits/stdc++.h>
using namespace std;
#define INF 1e7
int ex;
int n,T;
typedef pair<int,int> pp;
vector<vector<pp>> v;

int dijkstra(int s){
  vector<int> dis(n+1,INF);
  dis[s] = 0;
  priority_queue<pp,vector<pp>,greater<pp>> pq;
  pq.push(pp(0,s));
  while(!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    for(int i=0;i<v[u].size();++i){
      int child = v[u][i].second;
      int w = v[u][i].first;
      if(dis[u]+w < dis[child]){
        dis[child] = dis[u] + w;
        pq.push(pp(dis[child],child));
      }
    }
  }
  if(dis[ex]<=T)
    return 1;
  else return 0;


}

int main(){
int t;  cin>>t;
bool fl = false;

while(t--){
  if(fl)  cout<<endl;
  fl = true;
  int e;
  cin>>n>>ex>>T>>e;
  v.assign(n+1,vector<pp>());
  while(e--){
    int a,b,c;
    cin>>a>>b>>c;
    v[a].push_back(pp(c,b));
  }
int cnt = 0;
  for(int i=1;i<=n;++i){
    cnt+= dijkstra(i);
  }
cout<<cnt<<endl;
for(int i=0;i<v.size();++i)
  v[i].clear();

}

return 0;
}
