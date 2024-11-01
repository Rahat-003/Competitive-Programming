#include <bits/stdc++.h>
using namespace std;
typedef pair<string,string> ss;
typedef pair<int,ss> iss;

map<string,string> mp;
vector<iss> graph;
string f(string s){
  if(mp[s]!=s)
    mp[s] = f(mp[s]);
  return mp[s];
}
int k(){
  int ttl = 0;
  for(int i=0;i<graph.size();++i){
    string s = f(graph[i].second.first);
    string t = f(graph[i].second.second);
    int pz = graph[i].first;
    if(s!=t){
      ttl += pz;
      mp[t] = s;
    }
  }
  return ttl;
}

map<string,bool> vis;
map<string,vector<string>> check;

void dfs(string a){
  vis[a] = true;
  for(int i=0;i<check[a].size();i++){
    string child = check[a][i];
    if(!vis[child])
      dfs(child);
  }
}


int main(){
int n,e;
while(cin>>n>>e){
    if(!n && !e ) break;
  for(int i=0;i<n;i++){
    string s; cin>>s;
    mp[s] = s;
    vis[s] = false;
  }
  for(int i=0;i<e;i++){
    string s,t; int a;
    cin>>s>>t>>a;
    graph.push_back(iss(a,ss(s,t)));
    check[s].push_back(t);
    check[t].push_back(s);
  }

  string w; cin>>w;
  dfs(w);
  int a = 0;
  for(auto it = vis.begin();it!=vis.end();++it)
  if(!vis[it->first]){
    a=1;  break;
  }

if(a)
    cout<<"Impossible\n";
else{
  sort(graph.begin(),graph.end());

  int cost = k();
    cout<<cost<<endl;
}
check.clear();  vis.clear();
    graph.clear();
    mp.clear();
}
return 0;
}
