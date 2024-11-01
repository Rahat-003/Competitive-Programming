
#include <bits/stdc++.h>
using namespace std;
#define mx 103

typedef pair<int,int> pp;
unordered_map<int,int> mp;
unordered_map<int,bool> vis;
vector<vector<pp>> v;
#define inf 1e7
int cnt = -1;

double ans(int a,int b){
  return (double)a/(double) b;
}


int floyd(int n){
  vector<vector<int>> ar;
  ar.assign(n,vector<int>(n,inf));
  for(int i=0;i<ar.size(); i++){
    for(int j=0;j<ar[i].size(); j++){
      if(i==j)  ar[i][j] = 0;
      if(j<v[i].size()){
        int c = v[i][j].first;
        int d = v[i][j].second;
        ar[i][d] = c;
      }
    }
  }

  for(int k = 0;k<n; k++){
    for(int i = 0; i<ar.size(); i++){
      for(int j=0;j<ar[i].size(); j++){
        ar[i][j] = min(ar[i][j],ar[i][k] + ar[k][j]);
      }
    }
  }
  int ans = 0;
  for(int i = 0; i<ar.size(); i++)
    for(int j=0;j<ar[i].size(); j++)
      if(ar[i][j]!=inf) ans+= ar[i][j];

    return ans;
}

void make(int x,int y){
  int m,n;
  if(!vis[x]){
    vis[x] = true;
    mp[x] = ++cnt;
  }
  m = mp[x];
  if(!vis[y]){
    vis[y] = true;
    mp[y] = ++cnt;
  }
  n = mp[y];
  v[m].push_back(pp(1,n));
}

int main(){
int a,b;
cnt = -1;
int tc = 0;
while(true){
  cin>>a>>b;
  if(!a && !b)  break;
  v.assign(mx,vector<pp>());

  int x,y;
  x = a, y = b;
  make(x,y);
  while(cin>>x>>y){
    if(!x && !y)  break;
    make(x,y);
  }
int sum = floyd(cnt+1);
int totalPath = cnt*(cnt+1);

double click = ans(sum,totalPath);
printf("Case %d: average length between pages = ",++tc);

cout<<fixed<<setprecision(3)<<click<<" clicks\n";

mp.clear();
vis.clear();
cnt = -1;
for(int i=0;i<v.size(); i++)
  v[i].clear();

}

return 0;
}
