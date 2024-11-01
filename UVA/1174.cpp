#include <bits/stdc++.h>
using namespace std;
map<string,string> mp;
typedef  pair<string,string> ss;
typedef  pair<int,ss> iss;
vector<iss> graph;

string f(string s){
  if(mp[s]!=s)
  mp[s] = f( mp[s] );

  return mp[s];
}
int k(){
  int ttl = 0;
  for(int i=0;i<graph.size();i++){
    string s = f(graph[i].second.first);
    string t = f(graph[i].second.second);
    int pz = graph[i].first;
    if(s!=t){
      ttl += pz;
      mp[s] = t;
    }
  }
  return ttl;
}

int main(){
int tc; cin>>tc;
int fl = 0;
while(tc--){
  if(fl)  cout<<endl;
  fl=1;
  int n,e;  cin>>n>>e;
  for(int i=0;i<e;i++){
    string s,t; int c;
    cin>>s>>t>>c;
    mp[s] = s; mp[t] = t;
    graph.push_back(iss(c,ss(s,t)));
  }
  sort(graph.begin(),graph.end());
  /*
  for(int i=0;i<graph.size();i++)
    cout<<graph[i].second.first<<" "<<graph[i].second.second<<" "<<graph[i].first<<endl;
*/
  int cost = k();
  cout<<cost<<endl;
  graph.clear();
  mp.clear();
}


return 0;
}
