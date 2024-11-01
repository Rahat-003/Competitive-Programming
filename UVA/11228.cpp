#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> dd;
typedef pair<int,int> pp;
typedef pair<double,pp> ppp;

vector<ppp> graph,rail;
vector<int> ar;


double cal(double X,double Y,double x,double y){
  return sqrt( (x-X)*(x-X)+(y-Y)*(y-Y) );
}

int f(int a){
  if(ar[a]!=a)  ar[a] = f(ar[a]);
  return ar[a];
}

int k1(double th){
  double ans = 0;
  for(int i=0;i<graph.size(); i++){
    int x = graph[i].second.first;
    int y = graph[i].second.second;
    int px = f(x);
    int py = f(y);
    double pz  = graph[i].first;
    if(px!=py ){
     if(pz<=th){
      ans+= pz;
      ar[py] = px;
     }
     else {
      rail.push_back(ppp(pz,pp(x,y)));

    }

    }
  }
  int road = nearbyint(ans);
  return road;
}

int k2(){
  double ttl = 0;

  for(int i=0;i<rail.size(); i++){

    int x = rail[i].second.first;
    int y = rail[i].second.second;
    int px = f(x);
    int py = f(y);
    double pz  = rail[i].first;

    if(px!=py){
     ttl+= pz;
     ar[py] = px;
    }

  }

  int ans = nearbyint(ttl);
  return ans;
}



int main(){
//  freopen("tst.txt","r",stdin);
int t;
cin>>t;
for(int T=1;T<=t;T++){

  int n; double thr;
  cin>>n>>thr;

  vector<dd> v;
  for(int i=0;i<n;i++){
    double a,b;
    cin>>a>>b;
    v.push_back(dd(a,b));
    ar.push_back(i);
  }

  int i1=0;
  while(1){
    if(i1==v.size())  break;
    for(int i=i1+1;i<v.size();++i){
      double x1,x2,y1,y2;
      x1 = v[i1].first; y1 = v[i1].second;
      x2 = v[i].first; y2 = v[i].second;
      double w = cal(x1,y1,x2,y2);
      graph.push_back(ppp(w,pp(i,i1)));
    }
    i1+=1;
  }
  sort(graph.begin(),graph.end());

  int Road = k1(thr);

  sort(rail.begin(),rail.end());


  int state = 0;

  for(int i=0;i<ar.size();i++){
    ar[i] = f(ar[i]);
  }
  for(int i=0;i<ar.size(); i++){
    if(ar[i]==i)  state++;
  }

  int Rail = k2();

  printf("Case #%d: %d %d %d\n",T,state,Road,Rail);

  graph.clear();
  ar.clear();
//  br.clear();
  rail.clear();
}

return 0;
}
