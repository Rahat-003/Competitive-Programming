#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v,r;
vector<bool> vis1,vis2;

stack<int> stk;

void dfs1(int a){
  vis1[a] = true;
  for(int i = 0;i<v[a].size(); i++){
    int child = v[a][i];
    if(!vis1[child])
      dfs1(child);
  }
  stk.push(a);
}

void dfs2(int a){
  vis2[a] = true;
  for(int i = 0;i<v[a].size(); i++){
    int child = v[a][i];
    if(!vis2[child])
      dfs2(child);
  }
}

int main(){

int t, tc = 0;
cin>>t;
while(t--){
  int n,e;
  cin>>n>>e;
  v.assign(n,vector<int> () );
  r = v;
  vis1.assign(n,false);
  vis2 = vis1;

  while(e--){
    int a,b;
  cin>>a>>b;
  a--; b--;
  v[a].push_back(b);
  r[b].push_back(a);
  }

  for(int i = 0;i<n; i++)
    if(!vis1[i])
      dfs1(i);

  int cnt = 0;
  while(stk.empty()==false){
    int u = stk.top();
    stk.pop();
    if(!vis2[u]){
      cnt++;
      dfs2(u);
    }
  }

  printf("Case %d: %d\n",++tc,cnt);

}







return 0;
}
