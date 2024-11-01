#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<bool> vis;
int n,e;

void dfs(int a){
  vis[a] = true;

  for(int i=0;i<v[a].size(); i++){
    int child = v[a][i];
    if(!vis[child])
      dfs(child);
  }
}


bool isConnected(){
  int i;

  for(i=0;i<v.size(); i++)
    if( v[i].size()!=0 )  break;


  if(n==i)  return true;

  dfs(i);

  for(int j=0;j<vis.size(); j++){
    if( !vis[j] && v[j].size() )  return false;
  }

  return true;
}

int Euler(){
  if( !isConnected() )  return 0;

  int odd = 0;

  for(int i=0;i<v.size(); i++){
    if ( v[i].size() & 1 )  odd++;
  }

  if(odd>2) return 0;

  if(!odd)  return 2;

  else return 1;

  /// Odd must not be equal to 1..  So, possible values of odd is   >2 , 0, 2;


}

int main(){

while(cin>>n>>e){

v.assign(n,vector<int>());
vis.assign(n,false);

while(e--){
  int a,b;
  cin>>a>>b;
  v[a].push_back(b);
  v[b].push_back(a);
}

int E = Euler();

if(E==0)  puts("Not Eulerian graph");

if(E==1)  puts("Have Eulerian path");     ///semi eulerian graph

if(E==2)  puts("Have Eulerian cycle");         ///Eulerian graph


}

return 0;
}
