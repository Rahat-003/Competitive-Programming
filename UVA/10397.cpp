#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
typedef pair<double,double> dd;
typedef pair<double,pp> ppp;
vector<ppp> graph;
vector<int> ar;
vector<dd> v;
int n;

void clr(){
  graph.clear();  v.clear();  ar.clear();
}


double calc(double x1,double y1,double x2,double y2){
  double _x = (x1-x2)*(x1-x2);
  double _y = (y1-y2)*(y1-y2);
  double ans = sqrt(_x+_y);
  return ans;
}
void combination(){
  int i1=0;
  while(true){
    if(i1==v.size())  break;
    for(int i=i1+1;i<v.size();++i){
      double x1 = v[i1].first,   y1 = v[i1].second;
      double x2 = v[i].first,    y2 = v[i].second;
      double w = calc(x1,y1,x2,y2);
      graph.push_back(ppp(w,pp(i1,i)));
    }
    i1++;
  }
}
int f(int a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}

double k(int nw){
  double ttl = 0;
  for(int i=nw;i<graph.size();++i){
   int px = f(graph[i].second.first);
   int py = f(graph[i].second.second);
   double pz = graph[i].first;
   if(px!=py && pz>0){
      ttl+=pz;
      ar[py] = px;
   }
  }
  return ttl;
}

int main(){

while(cin>>n){
  for(int i=0;i<n;++i)
    ar.push_back(i);

  for(int i=0;i<n;++i){
    double x,y;
    cin>>x>>y;
    v.push_back(make_pair(x,y));
  }
  int nw; cin>>nw;
  double ini = 0 ;
  for(int j=0;j<nw;++j){
    int x,y;
    cin>>x>>y;
    x--;  y--;
    if(x>y) swap(x,y);
    double x1 = v[x].first,   y1 = v[x].second;
    double x2 = v[y].first,   y2 = v[y].second;
    double w = calc(x1,y1,x2,y2);
    graph.push_back(ppp(w,pp(x,y)));
    ini+=w;
    int px = f(x), py = f(y);
    if(px!=py)
      ar[py] = px;
  }
  //  sort(graph.begin(),graph.end());
    combination();
    sort(graph.begin()+nw,graph.end());

    double tt = k(nw);  //     ans = total;

    double total=0;
/*
    for(int i=0;i<graph1.size();++i)
      total+=graph1[i].first;
*/
  cout<<fixed<<setprecision(2)<<tt<<endl;
  clr();
}
return 0;
}
