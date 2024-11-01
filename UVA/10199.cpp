#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<bool> vis,ap;
vector<int> par,low,disc;

unordered_map<string,int> si;
unordered_map<int,string> is;

void dfs(int a){
  vis[a] = true;
  static int time = 0;
  low[a] = disc[a] = ++time;
  int children = 0;

  for(int i = 0;i<v[a].size(); i++ ){
    int child = v[a][i];
    if(!vis[child]){
      par[child] = a;
      children++;

      dfs(child);
      low[a] = min(low[a],low[child]);

      if(par[a]==-1 && children>1)
        ap[a] = true;
      if(par[a]!=-1 && low[child]>=disc[a] )
        ap[a] = true;

    }
    else if(child!=par[a])
      low[a] = min(low[a],disc[child]);

  }

}

int main(){

int n;
int tc = 0;


while(cin>>n){
  if(!n)  break;

  if(tc)  cout<<endl;

  v.assign(n,vector<int>());
  vis.assign(n,false);
  ap = vis;
  par.assign(n,-1);
  low.assign(n,0);
  disc = low;

  int id = -1;
  for(int i = 0;i<n;i++){
    string s;
    cin>>s;
    id++;
    si[s] = id;
    is[id] = s;
  }

  int e;
  cin>>e;
  while(e--){
    string a,b;
    int x,y;
    cin>>a>>b;
    x = si[a];  y = si[b];
    v[x].push_back(y);
    v[y].push_back(x);
  }

  for(int i = 0;i<n; i++){
    if(!vis[i])
      dfs(i);
  }
  vector<string> node;

  for(int i = 0;i<ap.size(); i++){
    if(ap[i]){
      string s = is[i];
      node.push_back(s);
    }
  }

  printf("City map #%d: %d camera(s) found\n",++tc,node.size());
  sort(node.begin(),node.end());
  for(int i = 0;i<node.size(); i++)
    cout<<node[i]<<endl;
  si.clear();
  is.clear();

}



return 0;
}
