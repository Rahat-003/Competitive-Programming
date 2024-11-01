#include <bits/stdc++.h>
using namespace std;
map<int,vector<pair<int,int>>> mp;
vector<bool> vis;

void dfs(int a){
  vis[a] = true;
  for(int i=0;i<mp[a].size();i++){
    int child = mp[a][i].first;
    if(!vis[child]){
      dfs(a);
    }
  }

}
int main(){
int n,e;
while(cin>>n>>e){
  if(!n && !e)  break;
  vis.assign(n+1,false);

  while(e--){
    int a,b,w;
    cin>>a>>b>>w;
    mp[a].push_back({b,w});
  }
dfs(1);
}


return 0;
}
