
/// Also See Uva 11060- Beverages

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<int> indegree;
int n,e;

void top_sort(){
  queue<int> q;
  for(int i=0;i<n;i++)
    if(!indegree[i])
      q.push(i);

  int cnt = 0;
  vector<int> ans;

  while(!q.empty()){
    int u = q.front();
    ans.push_back(u);
    q.pop();
    for(int i=0;i<v[u].size(); i++){
      int child = v[u][i];
      if(--indegree[child]==0)
        q.push(child);
      }
    cnt++;
  }

  if(cnt!=n){
    cout<<"cycle found\n";
    return;
  }
  for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
  cout<<endl;

}



int main(){

cin>>n>>e;
v.assign(n,vector<int>());
indegree.assign(n,0);

while(e--){
  int a,b;
  cin>>a>>b;
  v[a].push_back(b);
  indegree[b]++;

}
/*
for(int i=0;i<n;i++){
  if(!indegree[i])
}
*/
    top_sort();








return 0;
}
