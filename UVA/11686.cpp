#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> v;

vector<int> indeg;

void top_sort(){
  vector<int> ans;
  queue<int> q;
  for(int i = 0; i<n; i++){
    if(indeg[i]==0)
      q.push(i);
  }
  int cnt = 0;

  while(!q.empty()){
  cnt++;
    int u = q.front();
    ans.push_back(u);
    q.pop();

  for(int i=0;i<v[u].size(); i++){
    int child = v[u][i];
    if(--indeg[child]==0)
      q.push(child);
  }
  }

  if(cnt!=n){
//      cout<<cnt<<" ";
    puts("IMPOSSIBLE");

  }
else{

  for(int i = 0;i<ans.size(); i++)
    cout<<ans[i]+1<<endl;
}
}

int main(){

int e;

while(cin>>n>>e){
  if(!n && !e)  break;

  v.assign(n,vector<int>());

  indeg.assign(n,0);

  while(e--){
    int a,b;
    cin>>a>>b;  a--;  b--;
  v[a].push_back(b);
  indeg[b]++;
  }

  top_sort();



}

return 0;
}
