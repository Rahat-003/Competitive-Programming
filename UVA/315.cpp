#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<bool> vis,ap;
vector<int> par,low,disc;

void dfs(int a){
  vis[a] = true;
  static int time = 0;
  disc[a] = low[a] = ++time;
  int children = 0;

  for(int i=0;i<v[a].size(); i++){
    int child = v[a][i];
    if(!vis[child]){
      children++;
      par[child] = a;
      dfs(child);
      low[a] = min(low[a],low[child]);

      if( par[a]==-1 && children>1 )
        ap[a] = true;
      if( par[a]!=-1 && low[child]>=disc[a] )
        ap[a] = true;

    }
    else if( child!=par[a] )
      low[a] = min(low[a],disc[child]);
  }


}


int main(){


int n;

while(cin>>n){
  if(!n)  break;

  v.assign(n,vector<int>());
  vis.assign(n,false);
  ap = vis;
  par.assign(n,-1);

  low.assign(n,0);
  disc = low;

  string s;
  cin.ignore();
  while(getline(cin,s)){
    if(s[0]=='0') break;
    istringstream iss(s);
    int a,b;
    iss>>a;
    a--;
    while(iss>>b){
      b--;
      v[a].push_back(b);
      v[b].push_back(a);
    }
  }
  int cnt = 0;

  for(int i = 0;i<n;i++){
    if(!vis[i])
      dfs(i);
  }


  for(int i = 0 ;i<ap.size(); i++)
    if(ap[i]) cnt++;

  cout<<cnt<<endl;



}

return 0;
}
