#include <bits/stdc++.h>
using namespace std;

typedef pair<char,char> pp;
typedef pair<int,pp> ppp;
map<char,char> ar;
vector<ppp> graph;

char f(char c){
  if(ar[c]!= c)
    ar[c] = f(ar[c]);
  return ar[c];
}
void k(){
  for(int i=0;i<graph.size();++i){
    char px = f(graph[i].second.first);
    char py = f(graph[i].second.second);
    int pz = graph[i].first;
    if(px!=py && pz){
      cout<<graph[i].second.first<<"-"<<graph[i].second.second<<" "<<pz<<endl;
      ar[py] = px;
    }
  }
}

int main(){

int t;
cin>>t;
for(int tc=1;tc<=t;++tc){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    char c = 'A'+i;
    ar[c] = c;
  }
  cin.ignore();
  for(int i=0;i<n;i++){
    string s;
    int d, j=0;// k=i,l=j;
    getline(cin,s);
    for(int i=0;i<s.size();++i)
      if(s[i]==',') s[i] = ' ';

    stringstream ss(s);
    while(ss>>d){
      //if(k>l) swap(l,k);
    if(i<j)  graph.push_back(ppp(d,pp('A'+i,'A'+j)));
    else   graph.push_back(ppp(d,pp('A'+j,'A'+i)));
      j+=1;
    }

  }
  sort(graph.begin(),graph.end());
  printf("Case %d:\n",tc);
  k();
  graph.clear();
  ar.clear();
}

return 0;
}
