#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<bool> vis;
int n,e;
stack<int> stk;

void dfs(int a){
  vis[a] = true;
  for(int i=0;i<v[a].size(); i++){
    int child = v[a][i];
    if(!vis[child])
      dfs(child);
  }
stk.push(a);
}

void dfs2(int a){
  vis[a] = true;
  for(int i=0;i<v[a].size(); i++){
    int child = v[a][i];
    if(!vis[child])
      dfs2(child);
  }
//stk.push(a);
}


int main(){

int t;
cin>>t;

while(t--){
  cin>>n>>e;
  v.assign(n,vector<int>());
  vis.assign(n,false);

  while(e--){
    int a,b;
    cin>>a>>b;
    a--;  b--;
    v[a].push_back(b);
  }
  for(int i=0;i<n;i++){
    if(!vis[i])
      dfs(i);
  }
  vis.assign(n,false);
  int cnt = 0;

  while(!stk.empty()){
    int u = stk.top();
//    cout<<u<<" ";
    stk.pop();
    if(!vis[u]){
      dfs2(u);
      cnt++;
    }
  }
  cout<<cnt<<endl;

for(int i=0;i<v.size(); i++)
  v[i].clear();

vis.clear();


}
return 0;
}

