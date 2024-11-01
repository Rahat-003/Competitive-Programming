#include <bits/stdc++.h>
using namespace std;
int n;
vector<bool> vis;
map<int,vector<int> > mp;

void dfs(int s){
for(int i=0;i<mp[s].size();i++){
  int child = mp[s][i];
  if(!vis[child]){
  vis[child] = true;
    dfs(child);
}
}
}
void assgn(){

vis.assign(n+1,false);
vis[0] = true;
}

int main(){


while(cin>>n){
  if(!n) break;
  mp.clear();
  vis.clear();
    int e;
while(cin>>e){
    if(!e) break;
int neigh;
while(cin>>neigh){
  if(!neigh) break;
  mp[e].push_back(neigh);
}
}
int ns; cin>>ns;
while(ns--){
assgn();
int s;
cin>>s;

dfs(s);
int cnt = count(vis.begin(),vis.end(),false);
int c=0;
if(cnt){
cout<<cnt<<" ";
for(int i=0;i<vis.size();i++){
  if(!vis[i]){
      c++;
  if(c!=cnt)  cout<<i<<" ";
  else if(c==cnt) cout<<i;
  }
}
}
else cout<<cnt;

cout<<endl;
}
}
return 0;
}
