#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> mp;

void bfs(int s, int d){
  map<int,bool>vis;
  vis[s]=true;
  map<int,int>lvl;
  map<int,int>par;
  par[s] = -1;
  lvl[s]=0;
  queue<int>q;
  q.push(s);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i=0;i<mp[u].size(); i++){
      int child = mp[u][i];
      if(!vis[child]){
        vis[child] = true;
        lvl[child] = lvl[u]  + 1;
        q.push(child);
        par[child] = u;
      }
    }
  }
  vector<int>v;
  int a=d;
  while(1){
    if(a==-1) break;
    v.push_back(a);
    a = par[a];
  }
for(int i=v.size()-1; i>=0; i--)
  cout<<v[i]<<" ";
}


int main(){
  int n,e;
  cin>>e;
  while(e--){
    int a,b;
    cin>>a>>b;
    mp[a].push_back(b);
    mp[b].push_back(a);
  }
  int s,d;
  cin>>s>>d;
  bfs(s,d);
return 0;
}
