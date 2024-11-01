
/**
  Time complexity O(n^2)
--Check Whether there is a path from all vertex u to v;
--No necessary from v to all vertex u;


*/

#include <bits/stdc++.h>
using namespace std;

int n,e;
vector<vector<bool>> isPath;
vector<vector<int>> graph;

void dfs(int s,int d){
  isPath[s][d] = true;
  for(int i=0;i<graph[s].size(); i++){
    int child = graph[s][i];
    if(!isPath[s][child])
      dfs(s,child);
  }

}

int main(){

cin>>n>>e;
graph.assign(n,vector<int>());
isPath.assign(n,vector<bool>(n,false));

while(e--){
  int a,b;
  cin>>a>>b;
  graph[a].push_back(b);
}

for(int i=0;i<n;i++)
  dfs(i,i);

for(int i=0;i<n;i++){
  for(int j=0;j<n;j++)
    cout<<isPath[i][j]<<" ";
  cout<<endl;
}



return 0;
}
