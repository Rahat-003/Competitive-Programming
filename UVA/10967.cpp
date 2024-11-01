#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
typedef pair<char,pp> cpp;
typedef pair<int,pp> ppp;

#define INF 2e9
int graph[103][103],r,c;
int dis[103][103];
int dx[]= {1,0,0,-1};
int dy[] = {0,1,-1,0};
vector<ppp> v;
vector<int> rw;

void dj(){
  dis[r-1][0] = 1;
  priority_queue < ppp,vector<ppp>,greater<ppp>> pq;
  pq.push(ppp(1,pp(r-1,0)));
  while(!pq.empty()){
    int ux = pq.top().second.first;
    int uy = pq.top().second.second;
    int uw = pq.top().first;
    pq.pop();
    for(int i=10;i<14;++i){
      int nx = dx[i-10]+ux;
      int ny = dy[i-10]+uy;
      if(nx>=0 && nx<r && ny>=0 && ny<c){
        if(dis[nx][ny]>dis[ux][uy]+uw && graph[nx][ny]==1){
          dis[nx][ny] = dis[ux][uy]+uw;
          pq.push(ppp(dis[nx][ny],pp(nx,ny)));
        }
        if(graph[nx][ny]>=10 ){

        }
      }
    }

  }
}

int main(){
int t;
cin>>t;
while(t--){
  cin>>r>>c;
  int cnt=0;
  for(int i=0;i<r;++i){
   fill(dis[i],dis[i]+c,INF);
    for(int j=0;j<c;++j){
    char ch;
    cin>> ch;
    if(ch=='.') graph[i][j] = 1;
    if(ch=='#') graph[i][j] = -1;
    else {
        cnt++;
     if(ch=='N') {
        graph[i][j] = 11;
     v.push_back(ppp(cnt,pp(i-1,j)));
     }
     if(ch=='S'){
        graph[i][j] = 12;
     v.push_back(ppp(cnt,pp(i+1,j)));
     }
     if(ch=='E') {
        graph[i][j] = 10;
     v.push_back(ppp(cnt,pp(i,j+1)));
     }
     if(ch=='W') {
        graph[i][j] = 13;
      v.push_back(cpp(cnt,pp(i,j-1)));
    }
    }
  }
  }
  while(cnt--){
    int a;  cin>>a;
    rw.push_back(a);
  }
dj();



}


return 0;
}
