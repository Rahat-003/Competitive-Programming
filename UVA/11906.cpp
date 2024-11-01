#include <bits/stdc++.h>
using namespace std;
int r,c,x,y,w;
vector<vector<int>> v,cnt;
vector<vector<bool>> vis;
vector<int> dx,dy;

void dfs(int a,int b){
/*  if(vis[a][b])
    return;*/
  vis[a][b] = true;
  for(int i=0;i<dx.size();i++){
    int nx = a+dx[i], ny = b+dy[i];
    if(nx<r && nx>=0 && ny<c && ny>=0){
      if(v[nx][ny]!=-1){
        cnt[nx][ny]++;
        if(!vis[nx][ny]){
          dfs(nx,ny);
        }
      }
    }
  }
}

int main(){
//  freopen("11906.txt","r",stdin);
int t;  cin>>t;
for(int tc=1;tc<=t;tc++){
  cin>>r>>c>>x>>y>>w;
  v.assign(r,vector<int>(c,0));
  cnt.assign(r,vector<int> (c,0));
  vis.assign(r,vector<bool> (c,false));
  while(w--){
    int a,b;  cin>>a>>b;
    v[a][b] = -1;
    vis[a][b] = true;
  }
  if(x==y || !x || !y){
    dx = {x,-x,y,-y};
    dy = {y,-y,-x,x};
  }
  else{
    dx = {x,x,-x,-x,y,y,-y,-y};
    dy = {y,-y,y,-y,x,-x,x,-x};
  }
  dfs(0,0);
  int odd=0,even=0;
  for(int i=0; i<r; i++){
    for(int j=0;j<c;j++){
      if(cnt[i][j] || (!i && !j)){
        if(cnt[i][j] %2) odd++;
        else even++;
      }
    }
  }
  printf("Case %d: %d %d\n",tc,even,odd);
  for(int i=0;i<r;i++){
    v[i].clear();
    vis[i].clear();
    cnt[i].clear();
  }
}


return 0;
}
