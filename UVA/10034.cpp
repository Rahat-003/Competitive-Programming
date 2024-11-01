#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
typedef pair<double,double> dd;
typedef pair<int,dd> idd;
typedef pair<double,pp> dpp;

vector<int> ar;
vector<idd> ini;
vector<dpp> graph;

double weight(double x1,double y1,double x2,double y2){
  double _X = (x2-x1)*(x2-x1);
  double _Y = (y2-y1)*(y2-y1);
  return sqrt(_X + _Y);
}
int f(int a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}

double k(){
  double ttl = 0;
  for(int i=0;i<graph.size(); ++i){
    double px = f(graph[i].second.first);
    double py = f(graph[i].second.second);
    double pz = graph[i].first;
    if(px!=py){
      ttl += pz;
      ar[px] = py;
    }
  }
  return ttl;
}

int main(){
 // freopen("print.txt","w",stdout);
int tc;   cin>>tc;
int fl = 0;
while(tc--){

  if(fl)  cout<<endl;
  fl = 1;
  int a;  cin>>a;
  for(int i=0;i<a;i++){
    ar.push_back(i);
    double x,y;
    cin>>x>>y;
    ini.push_back(idd(i,dd(x,y)));
  }
  int c=0;
  while(1){
    c+=1;
    if(c==a)  break;
    for(int i=c-1;i<a;i++){
      if(c-1!=i){
        int n1 = ini[c-1].first;
        int n2 = ini[i].first;
        double x1 = ini[c-1].second.first;
        double y1 = ini[c-1].second.second;
        double x2 = ini[i].second.first;
        double y2 = ini[i].second.second;
        double w = weight(x1,y1,x2,y2);
        graph.push_back(dpp(w,pp(n1,n2)));
      }

    }
  }
  sort(graph.begin(),graph.end());
  double cost = k();
  ar.clear(); ini.clear();  graph.clear();
  cout<<fixed<<setprecision(2)<<cost<<endl;
}

return 0;
}
