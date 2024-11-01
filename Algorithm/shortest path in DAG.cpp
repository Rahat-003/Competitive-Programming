
#include <bits/stdc++.h>
using namespace std;

/// Shortest path from one given source to all other nodes

typedef pair<int,int> pp;
vector<vector<pp> > v;
vector<bool> vis;
#define inf 2e9

int n,e;

stack<int> stk;

void dfs(int a){
  vis[a]  = true;
  for(int i = 0;i<v[a].size(); i++){
   int child = v[a][i].first;
   if(!vis[child]){
    dfs(child);
   }

  }

stk.push(a);
}

void shortestPathInDAG(int s){

  vector<int> dis(n,inf);
  dis[s] = 0;

  while(stk.empty()==false){
    int u = stk.top();
    stk.pop();
//    cout<<u<<",";
    if(dis[u]!=inf){
      for(int i = 0;  i<v[u].size(); i++ ){
        int child = v[u][i].first;
        int w = v[u][i].second;

        dis[child] = min(dis[u]+w,dis[child]);

      }

    }


  }
puts("");
for(int i = 0;i<dis.size(); i++)
  cout<<i<<" "<<dis[i]<<endl;


}




int main(){

cin>>n>>e;
v.assign(n,vector<pp>()) ;
vis.assign(n,false);

while(e--){
  int a,b,c;
  cin>>a>>b>>c;
  v[a].push_back(pp(b,c));
//  v[b].push_back(pp(a,c));
}

for(int i = n-1;i>=0;i--){
  if(!vis[i])
    dfs(i);
}

int s;
cin>>s;
shortestPathInDAG(s);




return 0;
}
