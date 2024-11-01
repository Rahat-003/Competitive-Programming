
#include <bits/stdc++.h>
using namespace std;

int N,E;
vector<vector<int>> v;
vector<bool> vis;

int node_count(int a){
  int cnt = 1;
  vis[a] = true;
  for(int i=0;i<v[a].size(); i++){
    int child = v[a][i];
    if( child!=-1 && !vis[child] )  ///condition must not be like--> if( !vis[child] && child!=-1)
      cnt+= node_count(child);
  }
return cnt;
}

void removeEdge(int m,int n){

  auto it = find(v[m].begin(), v[m].end(), n);
  *it = -1;

  auto jt = find(v[n].begin(), v[n].end(), m);
  *jt = -1;
}

void addEdge(int m,int n){
  v[m].push_back(n);
  v[n].push_back(m);
}


bool isValidNextEdge(int m, int n){
//  if(n==-1) return false;

  int cnt = 0;
  for(int i=0;i<v[m].size(); i++){
    if(v[m][i]!=-1)
      cnt++;
  }
  if(cnt==1)  return true;

  int cnt1 = node_count(m);

  removeEdge(m,n);

  vis.assign(N,false);

  int cnt2 = node_count(m);

  addEdge(m,n);

  if(cnt1>cnt2) return false;
  else return true;
}


void print_path(int u){
    cout<<u<<endl;
  for(int i=0;i<v[u].size(); i++ ){
    int child = v[u][i];
    if(child!=-1 && isValidNextEdge(u,child)){
      cout<<u<<"-"<<child<<" ";
      removeEdge(u,child);
      print_path(child);
    }
  }
}


int main(){

cin>>N>>E;

v.assign( N,vector<int>() );
vis.assign(N,false);

while(E--){
  int a,b;
  cin>>a>>b;
  v[a].push_back(b);
  v[b].push_back(a);
}

int u = 0;
for(int i=0;i<N;i++){
  if( v[i].size() & 1 ){
    u = i;
    break;
  }
}

print_path(u);

return 0;
}
