#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<bool> vis;
vector<int> par,low,dis;
int n,e;

bool dfs(int a){
  vis[a] = true;
  static int time = 0;
  dis[a] = low[a] = ++time;

  int children = 0;

  for(int i = 0;i<v[a].size(); i++){
    int child = v[a][i];
    if(!vis[child]){
      par[child] = a;
      if(dfs(child))  return true;

      low[a] = min(low[a],low[child]);

      if(par[a]==-1 && children>1)
        return true;
      if(par[a]!=-1 && low[child]>=dis[a])
        return true;

    }
    else if(child!=par[a])
      low[a] = min(low[a], dis[child]);

  }



return false;

}

bool check(){

  if(dfs(0))
    return false;
  for(int i = 0;i<n;i++)
    if(!vis[i]) return false;
  return true;

}

int main(){

cin>>n>>e;
v.assign(n,vector<int>());
vis.assign(n,false);
par.assign(n,-1);
low.assign(n,0);
dis = low;

while(e--){
  int a,b;
  cin>>a>>b;
  v[a].push_back(b);
  v[b].push_back(a);
}

if(check())
  puts("true");
else puts("false");


return 0;
}
