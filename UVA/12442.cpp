#include <memory.h>
#include <map>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int mp[50002];
bool vis1[50002],vis2[50002];

int dfs(int a){
  vis1[a] = true;
  vis2[a] = true;
  int sum = 1,child = mp[a];
  if(!vis2[child]){
    sum+=dfs(child);
  }
  vis2[a] = false;
  return sum;
}

int main(){

int t;
cin>>t;
//  mp.assign(50002,0);
memset(vis2,false,sizeof vis2);
for(int tc=1;tc<=t;tc++){
  int n;
  cin>>n;
  memset(vis1,false,sizeof vis1);
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    mp[a] = b;
  }
  int mx=-1,f,i1;
  for(int i=1;i<=n;i++){
    if(!vis1[i]){
      f = dfs(i);
        cout<<i<<" "<<f<<endl;
      if(f>mx){
      i1 = i; mx = f;
      }
  }
  }
  printf("Case %d: %d\n",tc,i1);
//  vis1.clear(); vis2.clear(); mp.clear();
}

return 0;
}
