#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
typedef pair<int,pp> ipp;
#define MAX 1001
vector<ipp> v;
int n,e,ar[MAX];

int f(int a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}

int kruskal(){
  int ttl = 0;
  for(int i=0;i<v.size();i++){
  int px = f(v[i].second.first);
  int py = f(v[i].second.second);
  int pz = v[i].first;
  if(px!=py){
    ttl+=pz;
    ar[py] = px;
  }
  }
  return ttl;
}

int main(){

cin>>n>>e;
for(int i=0;i<n;i++)
  ar[i] = i;
for(int i=0,a,b,c;i<e;i++){
  cin>>a>>b>>c;
  v.push_back(ipp(c,pp(a,b)));
 // v.push_back(ipp(c,pp(b,a)));
}
sort(v.begin(),v.end());

int cost = kruskal();
cout<<cost<<endl;

return 0;
}
