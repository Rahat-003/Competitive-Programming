/*
#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
int r,c;
typedef pair<int,int> pp;
vector<vector<int>> graph;
vector<vector<pp>> v;

void dijkstra(){
vector<int> dis;

dis.assign(r*c,INF);
dis[0] = graph[0][0];
priority_queue <pp,vector<pp>,greater<pp>> pq;
pq.push(pp(dis[0],0));
    while(!pq.empty()){
      int u = pq.top().second;
      pq.pop();
      for(int i=0;i<v[u].size();++i){
        int child = v[u][i].second;
        int w = v[u][i].first;
        if(dis[u]+w<dis[child]){
          dis[child] = dis[u]+w;
          pq.push(pp(dis[child],child));
        }
      }
    }

  cout<<dis[r*c-1]<<endl;

}


int main(){

int t;
cin>>t;
while(t--){
  cin>>r>>c;
  graph.assign(r,vector<int>(c,0));
  v.assign(r*c,vector<pp>());
  for(int i=0;i<r;++i){
    for(int j=0;j<c;++j){
      int a;
      cin>>a;
      graph[i][j] = a;
    }
  }

  for(int i=0;i<r;i++){
    for(int j=0;j<c;++j){
      int m = c*i+j;
      int left = m-1;
      int top = m-c;
      if(j!=0){
        v[m].push_back(pp(graph[i][j],left));
        v[left].push_back(pp(graph[i][j],m));
      }
      if(i!=0){
        v[m].push_back(pp(graph[i][j],top));
        v[top].push_back(pp(graph[i][j],m));
      }
    }
  }
dijkstra();

for(int i=0;i<graph.size();++i)
  graph[i].clear();
for(int j=0;j<v.size();++j)
  v[j].clear();
}
return 0;
}
*/
///test case mile.. sala tarporeo wrong dise
/// nicherta ac

#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
#define ll long long
ll dx[] = {1,0,0,-1};
ll dy[] = {0,1,-1,0};
typedef pair<ll,ll> pp;
typedef pair<ll,pp> ppp;
ll r,c;
ll graph[1003][1003];
void dj(){
  ll dis[r][c];
  for(int i=0;i<r;++i)
    fill(dis[i],dis[i]+c,INF);
  dis[0][0] = graph[0][0];
  priority_queue<ppp,vector<ppp>,greater<ppp>> pq;
  pq.push(ppp(dis[0][0],pp(0,0)));
  while(!pq.empty()){
    ppp u = pq.top();
    ll sx = pq.top().second.first;
    ll sy = pq.top().second.second;
    pq.pop();
    for(int i=0;i<4;++i){
      ll nx = dx[i] + sx;
      ll ny = dy[i] + sy;
      if(nx>=0 && nx<r && ny>=0 && ny<c){
        if(dis[nx][ny] > dis[sx][sy]+graph[nx][ny] ){
          dis[nx][ny] = dis[sx][sy]+graph[nx][ny];
          pq.push(ppp(dis[nx][ny],pp(nx,ny)));
        }
      }
    }
  }
  cout<<dis[r-1][c-1]<<endl;
}

int main(){

ll t;
cin>>t;
while(t--){
  cin>>r>>c;
  for(int i=0;i<r;++i)
    for(int j=0;j<c;++j)
    cin>>graph[i][j];
  dj();

}


return 0;
}
