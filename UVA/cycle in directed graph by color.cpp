
/// Detect cycle in directed graph using color

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<int> color;

/**
    white = 0
    gray  = 1
    black = 2
*/

bool dfs(int a){

  color[a] = 1;

  for(int i = 0;i<v[a].size(); i++){
    int child = v[a][i];
    if(color[child]==1)
      return true;
    if( color[child]==0 && dfs(child) ) return true;
  }

  color[a] = 2;
  return false;
}


int main(){

int n,e;

cin>>n>>e;
v.assign(n,vector<int>());
color.assign(n,0);

while(e--){
  int a,b;
  cin>>a>>b;
  v[a].push_back(b);
}

int i;
for( i = 0;i<n;i++){

  if( color[i]==0 && dfs(i) ){
    puts("cycle");
    break;
  }

}

if(i==n)  puts("tree");




return 0;
}

