#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<bool> vis,color;

int n;

bool bipart(int a,int &tot){

  int T = 0, F = 0;


  vis[a] = true;

  T++;
  queue<int> q;
  q.push(a);
  color[a] = true;

  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i = 0; i<v[u].size(); i++){
      int child = v[u][i];

      if( !vis[child] && !color[child] ){
        color[child] = !color[u];
        if(color[child])  T++;
        else F++;
        vis[child] = true;
        q.push(child);
      }
      else if(color[child]==color[u]) return false;

    }
  }

  tot += max(T,F);



  return true;
}







int main(){

/*
freopen("tst.txt","r",stdin);
freopen("txt.txt","w",stdout);
*/

int t;
cin>>t;

while(t--){
    cin>>n;
  v.assign(n,vector<int>());
  vis.assign(n,false);
  color.assign(n,false);

  for(int i = 0;i<n;i++){
    int m;
    cin>>m;
    while(m--){
      int b;  cin>>b;
      b--;
      v[i].push_back(b);
      v[b].push_back(i);
    }
  }

  int tot = 0;
  for(int i = 0; i<n;i++){
    if(!vis[i] && bipart(i,tot) );

  }
  cout<<tot<<endl;

}

return 0;
}
