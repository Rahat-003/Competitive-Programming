#include <bits/stdc++.h>
using namespace std;
#define MAX 1003
typedef pair<int,int> pp;
typedef pair<int,pp> ipp;
int ar[MAX];
//  priority_queue<ipp,vector<ipp>,less<ipp>> pq;
vector<ipp> v;

int findpar(int a){
  if(ar[a]!=a)    ar[a] = findpar(ar[a]);

  return ar[a];
}

int kruskal(){
  int ttl = 0;
  for(int i=0;i<v.size();i++){
  int px = findpar(v[i].second.first);
  int py = findpar(v[i].second.second);
  int pz = v[i].first;
  if(px!=py){
    ttl += pz;
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
  v.push_back({c,{a,b}});
//  v.push_back({c,{b,a}});
}

sort(v.begin(),v.end());

int cost = kruskal();
cout<<cost;
return 0;
}
