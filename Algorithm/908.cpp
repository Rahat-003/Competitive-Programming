
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
typedef pair<int,pp> ppp;
vector<ppp> graph1,graph2;
vector<int> ar1,ar2;

int f1(int a){
  if(ar1[a]!=a)
    ar1[a] = f1(ar1[a]);
  return ar1[a];
}

int f2(int a){
  if(ar2[a]!=a)
    ar2[a] = f2(ar2[a]);
  return ar2[a];
}

int k1(){
  int ttl=0;
  for(int i=0;i<graph1.size();++i){
    int px = f1(graph1[i].second.first);
    int py = f1(graph1[i].second.second);
    int pz = graph1[i].first;
    if(px!=py){
      ttl+=pz;
      ar1[py] = px;
    }
  }
  return ttl;
}
int k2(){
  int ttl=0;
  for(int i=0;i<graph2.size();++i){
    int px = f2(graph2[i].second.first);
    int py = f2(graph2[i].second.second);
    int pz = graph2[i].first;
    if(px!=py){
      ttl+=pz;
      ar2[py] = px;
    }
  }
  return ttl;
}

int main(){
int n;
bool fl = false;
while(cin>>n){
    if(fl) cout<<endl;
    fl = true;

  //ar1.assign(n+1,0);
  for(int i=0;i<=n;++i)
    ar1.push_back(i);

  string s;
  int rest;
  cin.ignore();
  vector<int> tmp;

  while(1){
    getline(cin,s);
    stringstream ss(s);
    int a;
    while(ss>>a){
      tmp.push_back(a);
    }
    rest = tmp[0];
    if(tmp.size()==1) break;
    graph1.push_back(ppp(tmp[2],pp(tmp[1],tmp[0])));
    tmp.clear();
  }
  while(rest--){
      int a,b,c;
      cin>>a>>b>>c;
    graph1.push_back(ppp(c,pp(a,b)));
  }
  sort(graph1.begin(),graph1.end());
  int cost1 = k1() , cost2;

  int n2; cin>>n2;
  for(int i=0;i<=n2;i++)
    ar2.push_back(i);

  while(n2--){
    int a,b,c;  cin>>a>>b>>c;
    graph2.push_back(ppp(c,pp(a,b)));
  }

  sort(graph2.begin(),graph2.end());

  cost2 = k2();
  cout<<cost2<<endl<<cost1<<endl;
  ar1.clear();  ar2.clear();
  graph1.clear(); graph2.clear();
  tmp.clear();

}

return 0;
}
