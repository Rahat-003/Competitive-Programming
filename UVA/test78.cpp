#include <bits/stdc++.h>
using namespace std;

vector<int> v,sum;
vector<bool> vis;

int dfs(int m){
vis[m] = true;
int t = 0;
int child = v[m];

if(!vis[child] && child!=-1)
  t += 1 + dfs(child);
vis[m] = false;
return t;

}

int main(){
  freopen("12442.txt","r",stdin);
int tcc; cin>>tcc;
for(int tc=1;tc<=tcc;tc++){
    v.clear();
    vis.clear();
    sum.clear();
  int n;  cin>>n;
  v.assign(n+1,-1);
  sum.assign(n+1,-1);
  for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    v[x] = y;
  }
  int f=-1,i1;
  vis.assign(n+1,false);
  for(int i=1;i<=n;i++){
    if(sum[i]==-1){
    sum[i] = dfs(i);
    }
    if(sum[i]>f){
     f = sum[i];
     i1=i;
    }

  }
  printf("Case %d: %d\n",tc,i1);

}


return 0;
}
