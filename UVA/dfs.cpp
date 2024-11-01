#include <bits/stdc++.h>
using namespace std;
map<string,vector<string>> mp;
map<string,bool> vis;

void dfs(string s){
  vis[s] = true;
  cout<<s<<" ";
  for(int i=0;i<mp[s].size();++i){
    string child = mp[s][i];
    if(!vis[child])
      dfs(child);
  }

}

int main(){
int n,e;
cin>>e;
for(int i=0;i<e;i++){
  string a,b;
  cin>>a>>b;
  vis[a] = false; vis[b] = false;
  mp[a].push_back(b);
  mp[b].push_back(a);
}
string d; cin>>d;
dfs(d);


return 0;
}
