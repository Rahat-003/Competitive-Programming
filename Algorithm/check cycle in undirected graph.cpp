#include <bits/stdc++.h>
using namespace std;

/// Both connected and Disconnected graph;

/// Do not work for parallel edges-- input like
/**
    2 2
    0 1
    1 0
prints cycle;
*/

vector<vector<int>> v;
vector<bool> vis;

bool dfs(int s,int parent){

  vis[s] = true;

  for(int i=0;i<v[s].size();i++){
    int child = v[s][i];

    if(!vis[child]){
    if( dfs(child,s) )
      return true;
    }
    else  if( child!=parent )  return true;
  }

  return false;

}


int main(){
  int n,e;
  cin>>n>>e;
  v.assign(n+1,vector<int>());
  vis.assign(n+1,false);

  while(e--){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
/*
  if(dfs(0,-1)) puts("cycle found");
  else puts("tree");
*/

int i;
/*
for( i = 0;i<=n;i++){
  if(!vis[i])
  if( dfs(i,-1) ){
    puts("cycle");
    break;
  }
}


/*
if(dfs(0,-1))
*/
//cout<<vis[2]<<endl<<vis[3];

if(i==n)  puts("tree");
cout<<dfs(1,0)<<endl;

return 0;
}
