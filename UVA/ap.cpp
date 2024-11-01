#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<bool> vis,ap;
vector<int> par,low,disc;

void dfs(int a){
  vis[a] = true;
  static int time = 0;
  disc[a] = low[a] = ++time;
  int children = 0;

  for(int i = 0;i<v[a].size(); i++){
    int child = v[a][i];
    if(!vis[child]){
      ++children;
      par[child] = a;
      dfs(child);
      low[a] = min(low[a],low[child]);

      if(children>1 && par[a]==-1)
        ap[a] = true;
      if(par[a]!=-1 && low[child]>=disc[a] )
        ap[a] = true;


    }
    else if(child!=par[a])
      low[a] = min(low[a],disc[child]);

  }



}

int main(){

int n,e;

cin>>n>>e;
v.assign(n,vector<int>());
vis.assign(n,false);
ap = vis;
low.assign(n,0);
disc = low;
par.assign(n,-1);

while(e--){
  int a,b;
  cin>>a>>b;
  v[a].push_back(b);
  v[b].push_back(a);
}

  for(int i = 0;i<n;i++){
    if(!vis[i])
      dfs(i);
  }

for(int i=0;i<n;i++)
  if(ap[i])
    cout<<i<<" ";
cout<<endl;






return 0;
}
