#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<bool> vis;
vector<int> par,low,disc;

struct edge{
  int a,b;
  edge(int c,int d){
  if(c>d) swap(c,d);
  a = c;
  b = d;
  }

  bool operator<(const edge& e1)  const{
    if(a!=e1.a) return a<e1.a;
    else return b<e1.b;
  }

};

vector<edge> bridge;

void dfs(int a){
  static int time = 0;
  vis[a] = true;
  disc[a] = low[a] = ++time;


  for(int i = 0;i<v[a].size(); i++){
    int child = v[a][i];
    if(!vis[child]){
      par[child] = a;

      dfs(child);
      low[a] = min(low[a],low[child]);

      if( low[child] > disc[a] )
        bridge.push_back(edge(a,child));


    }
    else if(child!=par[a])
      low[a] = min(low[a],disc[child]);
  }


  }

int main(){

  int n;
  while(cin>>n){
//    if(!n)  break;

  vis.assign(n,false);
  par.assign(n,-1);
  low.assign(n,0);
  disc = low;
  v.assign(n,vector<int> () );
  cin.ignore();

  int a,b;  string s;
  for(int i = 0;i<n;i++){
   //   if(!s.size()) break;
  getline(cin,s);
  istringstream iss(s);
  iss>>a;
  char gar;
  int e;
  iss>>gar>>e>>gar;
    while(e--){
      iss>>b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
  }

  for(int i = 0;i<n;i++){
    if(!vis[i])
      dfs(i);
  }

  sort(bridge.begin(),bridge.end());

  printf("%d critical links\n",bridge.size());

  for(int i = 0;i<bridge.size(); i++){
    printf("%d - %d\n",bridge[i].a, bridge[i].b);
  }

  cout<<endl;
  bridge.clear();
}



return 0;
}
