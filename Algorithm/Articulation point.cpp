
/// ARTICULATION POINT

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<bool> vis;
vector<int> disc,low,par, ap;

void dfs(int a){
  vis[a] = true;
  static int time = -1;
  int children = 0;

  disc[a] = low[a] = ++time;

  for(int i= 0; i<v[a].size(); i++){
    int child = v[a][i];

    if(!vis[child]){
      children++;
      par[child] = a;

      dfs(child);

      low[a] = min(low[a],low[child]);    ///for tree edge

      if(children>1 && par[a] == -1)
        ap[a] = true;
      if( par[a]!=-1 && low[child] <= disc[a] ){
      //  cout<<a<<" "<<child<<"  --> "<< low[child ]<<"  "<<disc[a]<<endl;

        ap[a] = true;
      }
    }
    else if(child!=par[a]){
      low[a] = min(low[a],disc[child]);   /// update low[a] for having already visited child (for backedge)
    }
  }

}

int main(){

int n,e;
cin>>n>>e;
n++;
v.assign(n,vector<int>());
vis.assign(n,false);
ap.assign(n,0);
disc.assign(n,0);   ///discovered
low.assign(n,0);
par.assign(n,-1);

while(e--){
  int a,b;
  cin>>a>>b;
  v[a].push_back(b);
  v[b].push_back(a);
}

for(int i=0;i<n;i++){
  if(!vis[i])
    dfs(i);
}

for(int i=0;i<ap.size(); i++)
  if(ap[i])
    cout<<i<<" ";

    cout<<endl;
/*
for(int i = 0;i<n;i++)
  cout<<disc[i]<<" "<<low[i]<<endl;

*/
return 0;
}
