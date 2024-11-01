#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
typedef pair<int,pp> ipp;


int f(vector<int> ar, int x){
  if(ar[x]!=ar[x])
    ar[x]  = f(ar, ar[x]);
  return ar[x];
}

int k(vector<ipp> both, vector<int> ar){
  int ttl = 0;
  for(int i=0;i<both.size();++i){
    int px = f(ar,both[i].second.first);
    int py = f(ar,both[i].second.second);
    int pz = both[i].first;
  if(px<py) swap(px,py);
    if(px!=py){
      ttl += pz;
      ar[px] = py;
    }
  }
  return ttl;
}
int main(){
int fl = 0;
  int n;
while(cin>>n){
  if(fl)  cout<<endl;
  fl=1;
vector<int> ar1,ar2;
vector<ipp> graph1,graph2;

  ar2.clear();
  graph2.clear();
  ar1.assign( n+1, 0 );
  for(int i=1;i<=n;i++){
    ar1[i] = i;
    int a,b,c;  cin>>a>>b>>c;
    graph1.push_back(ipp(c,pp(a,b)));
  }
  int nn; cin>>nn;
  for(int i=0;i<nn;i++){
    ar1.push_back(n+i+1);
    int a,b,c;  cin>>a>>b>>c;
    graph1.push_back(ipp(c,pp(a,b)));
  }
  sort(graph1.begin(),graph1.end());
  int new_cost = k(graph1, ar1);
  int old;  cin>>old;
  ar2.assign(old+1,-1);
  for(int i=1;i<=old;++i){
    ar2[i] = i;
    int a,b,c;
    cin>>a>>b>>c;
    graph2.push_back(ipp(c,pp(a,b)));
  }
  ar1.clear();
  graph1.clear();
  sort(graph2.begin(),graph2.end());
 /* for(int i=0;i<graph2.size();++i)
    cout<<graph2[i].second.first<<" "<<graph2[i].second.second<<" "<<graph2[i].first<<endl;
*/
for(int i=0;i<ar2.size();++i)
  cout<<ar2[i]<<endl;

  int old_cost = k(graph2,ar2);
  cout<<old_cost<<endl<<new_cost<<endl;
}

return 0;
}
