#include <bits/stdc++.h>
using namespace std;
//#define MAX 200003
#define ll long long
typedef pair<ll,ll> pp;
typedef pair<ll,pp> ipp;
vector<ipp> graph;
vector<ll> ar;

ll f(ll a){

  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}

ll k(){
    ll ttl=0;
    for(ll i=0;i<graph.size();i++){
      ll px = f(graph[i].second.first);
      ll py = f(graph[i].second.second);
      ll pz = graph[i].first;
      if(px!=py){
        ttl += pz;
        ar[py] = px;
      }
    }
    return ttl;
}

int main(){

ll n,e;

while(cin>>n>>e){

  if(!n && !e)  break;

  ll total =0;
  graph.clear();
  ar.clear();
  for(ll i=0;i<n;i++)
    ar.push_back(i);

  for(ll i=0;i<e;i++){
    ll a,b,c;
    cin>>a>>b>>c;
    total+=c;
    graph.push_back(ipp(c,pp(a,b)));
  }
  sort(graph.begin(),graph.end());

  ll cost = k();
  cout<<total-cost<<endl;

}
return 0;
}
