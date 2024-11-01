#include <bits/stdc++.h>
using namespace std;

struct node{
  int c,a,b;
  node(int _c, int _a,int _b){
    c = _c;
   a = _a;
   b = _b;
  }
  bool operator < (const node& n1){
    return c<n1.c;
  }
};

int ar[1001];
vector<node> v;

int f(int a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}
int kruskal(){
  int ttl = 0;
  for(int i=0;i<v.size();++i){
    int px = f(v[i].a);
    int py = f(v[i].b);
    int pz = v[i].c;
    if(px!=py){
      ttl+=pz;
      ar[px] = py;
    }
  }
  return ttl;
}

int main(){
int n,e;
cin>>n>>e;
for(int i=0;i<n;i++)
  ar[i] = i;
for(int i=0;i<e;i++){
  int a,b,c;
  cin>>a>>b>>c;
  v.push_back(node(c,a,b));
}
sort(v.begin(),v.end());
int cost  = kruskal();
cout<<cost;
return 0;
}
