
#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> v;

int dx[] = {1,1,1,-1,-1,-1,0,0};
int dy[] = {0,1,-1,0,1,-1,1,-1};

int r,c;

int dfs(int x,int y){
  int cnt = 1;
  v[x][y] = '.';

  for(int i=0;i<8;i++){
    int nx = x+dx[i];
    int ny = y+dy[i];

    if( nx>=0 && nx<r && ny>=0 && ny<c && v[nx][ny]=='*' )
      cnt+=dfs(nx,ny);
  }
  return cnt;
}



int main(){

while(cin>>r>>c){
  if(!r && !c)  break;

  v.assign(r,vector<char>(c,'.'));

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      char x; cin>>x;
      v[i][j] = x;
    }
  }
  int ans = 0;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(v[i][j]=='*'){
        int star = dfs(i,j);
        if(star==1) ans++;
      }
    }
  }
  cout<<ans<<endl;

}

return 0;
}
