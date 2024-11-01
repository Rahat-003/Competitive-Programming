
/// FOR BOTH CONNECTED AND DISCONNECTED GRAPH

#include <bits/stdc++.h>
using namespace std;

int n,e;
vector<vector<int> > v;
vector<bool> vis,stk;

bool dfs(int a){

if(!vis[a]){

  vis[a] = true;
  stk[a] = true;

  for(int i=0; i<v[a].size(); i++){

    int child = v[a][i];

    if(!vis[child] && dfs(child))
      return true;

    else if(stk[child])  return true;
  }
}

  stk[a] = false;

  return false;

}

bool check(){
  for(int i=1;i<=n;i++)
    if(dfs(i))  return true;

  return false;
}

int main(){

cin>>n>>e;

v.assign(n+2,vector<int>());
vis.assign(n+2,false);

stk = vis;

while(e--){
  int a,b;
  cin>>a>>b;
  v[a].push_back(b);
}


if( check()/* dfs(5)*/ ) puts("Cycle");
else puts("No cycle");

/*
for(int i = 0;i<stk.size(); i++)
  cout<<stk[i]<<" ";

cout<<endl;
*/

return 0;
}
