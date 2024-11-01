#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
typedef pair<double,pp> ppp;
vector<ppp> graph;
vector<int> ar;
vector<bool> vis;
vector<pair<double,double>> v,all;

int n;
void clr(){
  graph.clear();
  ar.clear(); vis.clear();
  v.clear();
  all.clear();
}

int f(int a){
  if(ar[a]!=a)
    ar[a]=f(ar[a]);
  return ar[a];
}

bool k(int gv){
  //cout<<gv<<endl;
  bool m = false;
  for(int i=gv;i<graph.size();++i){
    int px = f(graph[i].second.first);
    int py = f(graph[i].second.second);
    double pz = graph[i].first;
    if(px!=py){
        cout<<graph[i].second.first+1<<" "<<graph[i].second.second+1<<endl;
      m = true;
      ar[py] = px;
    }
  }
  return m;
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

int main(){

int t;
cin>>t;
bool fl = false;
while(t--){
  if(fl)  cout<<endl;
  fl=true;
  cin>>n;
  for(int i=0;i<n;++i){
    ar.push_back(i);
    vis.push_back(false);
}
  for(int i=1;i<=n;++i){
    double x,y;
    cin>>x>>y;
    v.push_back(make_pair(x,y));
  }
//  vis[0] = true;
  int given;  cin>>given;

  for(int i=0;i<given;++i){
    int a,b;  cin>>a>>b;
    if(a>b) swap(a,b);
    a--;  b--;
   // vis[a] = vis[b] = true;
        double x1 = v[a].first,   y1 = v[a].second;
        double x2 = v[b].first,    y2 = v[b].second;
        double w = calc(x1,y1,x2,y2);
      graph.push_back(ppp(w,pp(a,b)));
    int px = f(a),  py=f(b);
    if(px!=py){
      ar[py] = px;
    }
  }


    combination();
  sort(graph.begin()+given , graph.end());
  bool  mm = k(given);

  if(!mm)
    printf("No new highways need\n");

  clr();
}

return 0;
}
