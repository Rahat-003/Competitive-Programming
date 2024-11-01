#include <bits/stdc++.h>
using namespace std;
int r,c,p1,p2,w;
int even,odd;
vector<vector<int>> v,mp;
vector<vector<bool>> vis;

vector<int> dx,dy;

bool dec(int a,int b){
if(a<r && a>=0 && b<c && b>=0){
  if(vis[a][b])
    return true;
  else return false;
}
else return false;
}

void dfs(int a,int b){
      mp[a][b]++;
  if(vis[a][b])
    return ;
  vis[a][b] = true;
 // int sum=0;
  for(int i=0;i<dx.size();i++){
    int nx = a+dx[i], ny = b+dy[i];
    if(dec(nx,ny)){
  //    sum+=1;
      dfs(nx,ny);
    }
  }


}

int main(){
  freopen("11906.txt","r",stdin);
int T; cin>>T;
for(int tc=1;tc<=T;tc++){
  cin>>r>>c>>p1>>p2>>w;
  v.assign(r,vector<int>(c,0));
  mp.assign(r,vector<int>(c,0));
  vis.assign(103,vector<bool>(103,false));
  odd=even=0;
  if(p1<p2) swap(p1,p2);  ///p1 is greater
  if(!p2){
    dx = {p1,-p1,0,0};
    dy = {0,0,p1,-p1};
  }
  else if(p1==p2){
    dx = {p1,p1,-p1,-p1};
    dy = {p2,-p2,p2,-p2};
  }
  else {
    dx = {p1,p1,-p1,-p1,p2,p2,-p2,-p2};
    dy = {p2,-p2,p2,-p2,p1,-p1,p1,-p1};
  }
  while(w--){
    int a,b;  cin>>a>>b;
    v[a][b] = -1;
    vis[a][b] = false;
  }
  dfs(0,0);

for(int i=0;i<c;i++){
  for(int j=0;j<r;j++){
    if(mp[i][j]){
    if(mp[i][j] & 1)  odd++;
    else even++;
    }
  }
}

//printf("Case %d: %d %d\n",tc,even,odd);
dx.clear(); dy.clear();
//for(int i=0;i<)
}




return 0;
}
