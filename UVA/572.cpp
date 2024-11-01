#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vis;

int r,c;
int dx[] = {1,1,1,-1,-1,-1,0,0};
int dy[] = {0,1,-1,0,1,-1,1,-1};

void dfs(int x,int y){
  vis[x][y]=2;

  for(int i=0;i<8;i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(nx>=0 && nx<r && ny>=0 && ny<c && vis[nx][ny]==1 )
      dfs(nx,ny);
  }
}

int main(){


while(cin>>r>>c){
    if(!r && !c)  break;
    vis.assign(r,vector<int>(c,0));

    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        char C;
        cin>>C;
        if(C=='@')  vis[i][j] = 1;
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

  for(int i=0;i<vis.size(); i++)
    vis[i].clear();


}

return 0;
}
