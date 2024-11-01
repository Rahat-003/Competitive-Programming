
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph, reverse_graph ;
vector<bool> vis1,vis2;
stack<int> stk;

void dfs1(int a){
  vis1[a] = true;

  for(int i =0;i<graph[a].size(); i++){
    int child = graph[a][i];
    if(!vis1[child])
      dfs1(child);
  }
  stk.push(a);

}

void dfs2(int a){
  vis2[a] = true;
  cout<<a<<" ";

  for(int i=0;i<reverse_graph[a].size(); i++){
    int child = reverse_graph[a][i];
    if(!vis2[child])
      dfs2(child);
  }
}


int main(){

int n,e;
cin>>n>>e;

graph.assign(n+3,vector<int>());

reverse_graph = graph;  ///making equal means assigning reverse_graph has the same number of rows as graph has.

vis1.assign(n+5,false);
vis2 = vis1;

while(e--){
  int a,b;
  cin>>a>>b;
//  a--;b--;
  graph[a].push_back(b);
  reverse_graph[b].push_back(a);

}

for(int i=1;i<=n;i++){
  if(!vis1[i])
    dfs1(i);
}

while(!stk.empty()){
  int u = stk.top();
  stk.pop();

  if(!vis2[u]){
    dfs2(u);
  cout<<endl;
  }
}

return 0;
}

