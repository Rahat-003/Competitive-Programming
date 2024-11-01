#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<bool> color,vis;
int n,e;


bool bipart(int a,int& tot){
  vis[a] = true;
  queue<int> q;
  q.push(a);
  color[a] = true;

  int T = 0, F = 0;
  T++;

  while(!q.empty()){
    int u = q.front();
    q.pop();

    for(int i = 0; i<v[u].size(); i++){
      int child = v[u][i];

      if( !vis[child]  && !color[child]){
        vis[child] = true;
        q.push(child);
        color[child] = !color[u];

        if(color[child]) T++;
        else  F++;

      }
      else if(color[child]==color[u]) return false;
    }
  }
  if(T && F)  tot+= min(T,F);
  else tot+=1;


return true;
}



int main(){
/*
  freopen("tst.txt","r",stdin);
  freopen( "t.txt","w",stdout);
*/
int t;
cin>>t;
while(t--){
  cin>>n>>e;
  v.assign(n,vector<int>());
  color.assign(n,false);
  vis = color;

  while(e--){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  bool fl = true;


  int T = 0, F = 0;
  int ans = 0;

  for(int i=0;i<n;i++){
    if( !vis[i] && !bipart(i,ans) ){
      fl = false;
      break;
    }
  }

if(fl)  cout<<ans<<endl;
else puts("-1");

}


return 0;
}
