#include <bits/stdc++.h>
using namespace std;

int r,c;
vector<vector<int>> graph,vis;

int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};


void dfs(int x,int y){

  vis[x][y] = 2;
  for(int i=0;i<8;i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(nx>=0 && nx<r && ny>=0 && ny<c && vis[nx][ny]==1)
      dfs(nx,ny);
  }


}

int main(){

cin>>r>>c;
graph.assign(r,vector<int>(c,0));
vis = graph;

for(int i=0;i<r;i++){
  for(int j=0;j<c;j++){
    int x;  cin>>x;
    graph[i][j] = x;
 if(x)   vis[i][j] = 1;
  }
}
int cnt = 0;

for(int i=0;i<r;i++){
  for(int j=0;j<c;j++){
    if(vis[i][j]==1){
      cnt++;
      dfs(i,j);
    }
  }
}


cout<<cnt<<endl;


return 0;
}
