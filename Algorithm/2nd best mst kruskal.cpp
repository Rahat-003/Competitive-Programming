///uva 10600, 10462

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pp;
typedef pair<int,pp> ppp;

vector<ppp> graph, store;

vector<int> ar,collect,par;

int n,e;

void clr(){
  graph.clear();  ar.clear();
  store.clear();  collect.clear();
  par.clear();
}

int f(int a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}

void ar_make(){
  for(int i=0;i<n;++i)
    ar.push_back(i);
}

int k(){
  int ttl = 0;
  for(int i=0;i<graph.size();++i){
    int x = graph[i].second.first;
    int y = graph[i].second.second;

    int px = f(x);
    int py = f(y);
    int pz = graph[i].first;


    if(px!=py){
      store.push_back(ppp(pz,pp(x,y)));
      ttl+=pz;
      ar[py] = px;
    }
  }
  return ttl;
}

int k2(int a,int b,int c){
  int ttl = 0;
  if(par[a]>1 && par[b]>1) {
      ar_make();
  for(int i=0;i<graph.size();++i){
    int x = graph[i].second.first;
    int y = graph[i].second.second;

    int px = f(x);
    int py = f(y);
    int pz = graph[i].first;


    if(px!=py ){
        if(x==a && y==b)  continue;
  //    store.push_back(ppp(pz,pp(x,y)));
      ttl+=pz;
      ar[py] = px;
    }
  }
  }
  return ttl;
}


int main(){
int tc; cin>>tc;
  while(tc--){
    cin>>n>>e;
    ar_make();
    par.assign(n,0);
    for(int i=0;i<e;++i){
      int a,b,c;
      cin>>a>>b>>c;
      a--;  b--;
    par[a]++; par[b]++;
      graph.push_back(ppp(c,pp(a,b)));
    }

    sort(graph.begin(),graph.end());

    int mst1 = k();
    int mst2 = 1e7;

    for(int i=0;i<store.size();++i){
      ar.clear();
   //   ar_make();
      int a = store[i].second.first;
      int b = store[i].second.second;
      int c = store[i].first;

      int p = k2(a,b,c);
     // collect.push_back(mst2);
      if(p<mst2 && p>=mst1)  mst2 = p;
    }

    cout<<mst1<<" "<<mst2<<endl;

  clr();
  }
return 0;
}
