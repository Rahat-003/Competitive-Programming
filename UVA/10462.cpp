

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> node;
/*
struct node{
  int a,b,c;
  node(int x=0,int y=0,int z=0){
  a = x;
  b = y;
  c = z;
  }

  bool operator<(const node& n1)  const {
  if(c!=n1.c) return c<n1.c;
  return true;
  }


};
*/

vector<int> ar,par;
vector<node> graph, store;

int f(int a){
  if(ar[a]!=a)  ar[a] = f(ar[a]);
  return ar[a];
}

void clr(){
  graph.clear();  store.clear();  ar.clear();
  par.clear();
}

int k1(){
  int ttl = 0;
  for(int i=0;i<graph.size(); i++){
    int x = graph[i].second.first;
    int y = graph[i].second.second;

    int px = f(x);
    int py = f(y);
    int pz = graph[i].first;
    if(px!=py){
      store.push_back(node(pz,make_pair(x,y)));
      ttl+=pz;
      ar[py] = px;
    }
  }
  return ttl;
}
void ar_make(int n){
  for(int i=0;i<n;i++)
    ar.push_back(i);
}
int k2(int A,int B,int C){
  int ttl = 0;
  int same = 0;
  if(par[A]>1 && par[B]>1){
//    ar_make(n);
    for(int i=0;i<graph.size(); i++){
      int x = graph[i].second.first;
      int y = graph[i].second.second;
      int z = graph[i].first;
      int px = f(x);
      int py = f(y);
      if(px!=py){
        if(x==A && y==B && z==C && !same ){
        same++;
        continue;
        }

        ttl+= z;
        ar[py] = px;
      }
    }
  }
  return ttl;
}


int main(){

// freopen("tst.txt","r",stdin);

int tc;
cin>>tc;

for(int T=1;T<=tc; T++){
  int n;
  int e;
  cin>>n>>e;
  ar_make(n);
  par.assign(n,0);

  map<int,int> mp;
  map<int,bool> vis;

  int cnt = -1;

  while(e--){
    int a,b,c;
    cin>>a>>b>>c;

    if(!vis[a]){
        cnt++;
    mp[a] = cnt;
    vis[a] = true;
    }
    if(!vis[b]){
        cnt++;
      mp[b] = cnt;
    vis[b] = true;
    }
    int x = mp[a];
    int y = mp[b];

//    a--;  b--;
/*
    par[a]++;
    par[b]++;
*/  par[x]++;
    par[y]++;
//    graph.push_back(node)
    graph.push_back(node(c,make_pair(x,y)));
  }












sort(graph.begin(),graph.end());

int mst1 = k1();

int mst2 = 2e9;

  for(int i=0;i<ar.size(); i++){
   ar[i] = f(ar[i]);
  }

  int number = 0;

  for(int i=0;i<ar.size(); i++){
    if(ar[i]==i)  number++;
  }

  printf("Case #%d : ",T);

  if(number>1)  puts("No way");

  else{

  for(int i=0;i<store.size(); i++){
    int x = store[i].second.first;
    int y = store[i].second.second;
    int z = store[i].first;
    ar.clear();
    ar_make(n);
    int M = k2(x,y,z);
    if(M>=mst1 && M<mst2 )  mst2 = M;
  }

  if(mst2==2e9)  puts("No second way");
  else cout<<mst2<<endl;
  }

//cout<<mst1<<" "<<mst2<<" "<<number<<endl;
clr();

}







return 0;
}
