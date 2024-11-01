#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pp;
typedef pair<long long,pp> ipp;
vector<ipp> graph;
vector<long long> ar;
vector<bool> vis;
long long f(long long a){
if(ar[a]!=a)
  ar[a] = f(ar[a]);
  return ar[a];
}
void k(){
  long long edge = 0;
    for(long long i=0;i<graph.size();++i){
      long long px = f(graph[i].second.first);
      long long py = f(graph[i].second.second);
      long long pz = graph[i].first;
      long long n1 = graph[i].second.first;
      long long n2 = graph[i].second.second;
      if(px!=py){
        edge++;
        ar[py]=px;
      vis[i] = true;
      }
    }
}

int main(){
  long long n,e;
while(cin>>n>>e){
  if(!n && !e)  break;
  for(long long i=0;i<n;i++){
    ar.push_back(i);
  }
  for(long long i=0;i<e;i++){
    long long a,b,c;
    cin>>a>>b>>c;
    graph.push_back(ipp(c,pp(a,b)));
    vis.push_back(false);
  }
  sort(graph.begin(),graph.end());
  k();
    long long d=0;
    for(long long i=0;i<graph.size();++i){
      if(!vis[i]){
    if(d) cout<<" ";
    cout<<graph[i].first;
    d=1;
      }
    }
  if(!d) cout<<"forest";
  cout<<endl;
  ar.clear(); vis.clear();  graph.clear();
}

return 0;
}
