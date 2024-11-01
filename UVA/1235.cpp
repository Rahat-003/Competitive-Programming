#include <bits/stdc++.h>
using namespace std;
typedef pair<string,string> pp;
typedef pair<int,pp> ppp;
int data[] = {0,1,2,3,4,5,4,3,2,1};

vector<ppp> graph;
map<string,string> ar;
vector<string> all;
int weight(string a, string b){
  int w = 0;
  for(int i=0;i<a.size();++i){
    int aa = a[i] - '0';
    int bb = b[i] - '0';
    int c = aa-bb;
    c = abs(c);
    w+= data[c];
  }
  return w;
}
string f(string a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}
int k(){
  int ttl=0;
  for(int i=0;i<graph.size();++i){
    string px = f(graph[i].second.first);
    string py = f(graph[i].second.second);
    int pz = graph[i].first;
    if(px!=py){
      ttl+=pz;
      if(rand()%2)  swap(px,py);
      ar[py] = px;
    }
  }
  return ttl;
}

int main(){
int t;  cin>>t;

while(t--){
  int a;  cin>>a;
 // ar["0000"] = "0000";
 int cmp = 1e4;
  while(a--){
  string b;
  cin>>b;
  ar[b] = b;
  all.push_back(b);
  int c=0;
  for(int i=0;i<b.size();++i){
    int i1 = b[i] - '0';
    c+= data[i1];
  }
   if(c<cmp){
    graph.clear();
    cmp=c;
    graph.push_back(ppp(c,pp("0000",b)));
   }
}
  int d=0;
    while(1){
      if(d==all.size()) break;
      for(int i=d+1;i<all.size();++i){
        int w = weight(all[d],all[i]);
        graph.push_back(ppp(w,pp(all[d],all[i])));
      }
      d+=1;
    }
  sort(graph.begin(),graph.end());
  int cost = k();
  cout<<cost<<endl;
  graph.clear();  ar.clear(); all.clear();
}

return 0;
}
