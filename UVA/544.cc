#include <bits/stdc++.h>
using namespace std;

typedef pair<string,string> ss;
typedef pair<int,ss> iss;

vector<iss> graph;
map<string,string> ar;

string f(string a){
  if(ar[a]!=a)
    ar[a] = f(ar[a]);
  return ar[a];
}

int k(string s, string d){
  int ttl = 2e9;
  for(int i=0;i<graph.size();++i){
    int pz = graph[i].first;
    string px = f(graph[i].second.first);
    string py = f(graph[i].second.second);

    if(px!=py){
        if(pz<ttl)
        ttl = pz;

    ar[py] = px;

    if(ar[s]==ar[d]) break;
    }

  }
return ttl;
}


int main(){
int n,e;
int tc = 0;
bool fl = false;
while(true){

    tc++;
    if(fl) cout<<endl;
    cin>>n>>e;
    if(!n && !e) break;
    fl = true;
  while(e--){
  string a,b;
  int c;
  cin>>a>>b>>c;
  ar[a] = a;    ar[b] = b;
  graph.push_back(iss(c,ss(a,b)));
}
  sort(graph.begin(),graph.end(),greater<iss>());


  string s,d;
  cin>>s>>d;
  int ans = k(s,d);

  printf("Scenario #%d\n%d tons\n",tc,ans);

graph.clear();  ar.clear();
}



return 0;
}
