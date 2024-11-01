#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<bool> vis;

void dfs(int a){
  vis[a] = true;
  cout<<a<<" ";
  for(int i=0;i<v[a].size(); i++){
    int child = v[a][i];
    if(!vis[child])
      dfs(child);
  }
}


int main(){

int n,e;
cin>>n>>e;
vis.assign(n,false);
v.assign(n,vector<int>());

while(e--){
  int a,b;
  cin>>a>>b;
  v[a].push_back(b);
  v[b].push_back(a);
}

for(int i=0;i<n;i++){
  if(!vis[i]){
    dfs(i);
  cout<<endl;
  }
}
return 0;
}
