#include <bits/stdc++.h>
using namespace std;

char d = 'T';
int n;
vector<vector<char>> v,store;

int dx[] = {-1,-1,0,0,1,1};
int dy[] = {-1,0,-1,1,0,1};

void dfs(int x,int y, char q,int ix, int iy){

  if( (!ix && !iy) && (x==n-1 && q=='b') || (y==n-1 && q=='w') ){
    d = q;
    return;
  }

  if(x==n-1 && q=='b'){
    d = q;
    return ;
  }
  if(y==n-1 && q=='w'){
    d = q;
    return ;
  }
  v[x][y] = '0';

  for(int i=0;i<6;i++){
    int nx = x+dx[i];
    int ny = y+dy[i];

    if(nx>=0 && nx<n && ny>=0 && ny<n && v[nx][ny]==q){

      dfs(nx,ny,q,ix,iy);
    }
  }
}

int main(){
int tc = 0;

while(cin>>n){
    if(!n)  break;
  v.assign(n,vector<char>(n,'.'));
  store = v;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      char c;
      cin>>c;
      v[i][j] = c;
    }
  }
  store = v;

  for(int i=0;i<n;i++){

      v = store;
  if(v[i][0]=='w')   dfs( i, 0, v[i][0],i,0 );
      if(d!='T')  break;

      v = store;
  if(v[0][i]=='b')    dfs( 0, i, v[0][i],0,i);
      if(d!='T')  break;

  }
  if(d=='w')  d = 'W';
  if(d=='b')  d = 'B';

  printf("%d %c\n",++tc,d);
  d = 'T';
  for(int i=0;i<store.size();i++)
    store[i].clear();
}

return 0;
}
