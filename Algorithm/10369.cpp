
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
typedef pair<double,pp> ppp;

vector<ppp> graph;
vector<int> ar;
vector<double> graph1;
vector<pair<double,double>> v;
//vector<vector<pair<double,int>>> mp;
int n;
void clr(){
  graph1.clear();
  graph.clear();
  ar.clear();
  v.clear();
}

double calc(double x1,double y1,double x2,double y2){
  double _x = (x1-x2)*(x1-x2);
  double _y = (y1-y2)*(y1-y2);
  double ans = sqrt(_x+_y);
  return ans;
}
int f(int a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}

void k(){
  for(int i=0;i<graph.size();++i){
   int px = f(graph[i].second.first);
   int py = f(graph[i].second.second);
   int x = graph[i].second.first;
   int y = graph[i].second.second;
   double pz = graph[i].first;
   if(px!=py && pz){
    graph1.push_back(pz);
    ar[py] = px;
   }
  }
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

int main(){

int t;  cin>>t;
while(t--){
  int sat;
  cin>>sat>>n;
  for(int i=0;i<n;++i){
    ar.push_back(i);
  }
  for(int i=0;i<n;++i){
  double x,y; cin>>x>>y;
  v.push_back(make_pair(x,y));
  }
  //mp.assign(n,vector<pair<double,int>> ());
  combination();
  sort(graph.begin(),graph.end());
  k();
  sort(graph1.begin(),graph1.end(), greater<double>());
  if(sat)
  sat-=1;
  /*
  for(int i=0;i<graph1.size();++i)
    cout<<graph1[i].first<<endl;
*/
  cout<<fixed<<setprecision(2)<<graph1[sat]<<endl;
  clr();
}
return 0;
}
