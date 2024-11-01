
/// BRIDGE

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<bool> vis;
vector<int> low,disc,par;


void dfs(int a){

  vis[a] = true;
  static int time = 0;
  disc[a] = low[a] = ++time;

  for(int i=0;i<v[a].size(); i++){
    int child = v[a][i];
    if(!vis[child]){
      par[child] = a;
      dfs(child);
    low[a] = min(low[a],low[child]);

    if( low[child] > disc[a] )
      cout<<"Bridge edge "<<a<<" "<<child<<endl;
    }
    else if(child!=par[a])
      low[a] = min(disc[child],low[a]);

  }


}


int main(){

int n,e;
cin>>n>>e;

vis.assign(n+2,false);
v.assign(n+2,vector<int>());
disc.assign(n+2,0);
low.assign(n+2,0);
par.assign(n+2,-1);

while(e--){
  int a,b;
  cin>>a>>b;
  v[a].push_back(b);
  v[b].push_back(a);
}
cout<<endl;
for(int i=1;i<=n;i++){
    if(!vis[i]){
        dfs(i);
    }
}







return 0;
}
