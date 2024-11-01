#include <bits/stdc++.h>
using namespace std;
int n;

vector<bool> vis;
map<int,vector<int>>mp;
map<int,int>no;

void bfs(int a){
vector<int>lvl()

}

int main(){
  freopen("12442.txt","r",stdin);

int tc;
cin>>tc;

for(int cs=1; cs<=tc; cs++){
    mp.clear();
    no.clear();
  cin>>n;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    mp[a].push_back(b);
  }
  int f=-1, i1;

  for(int i=1;i<=n;i++){
  vis.assign(n+1,false);
    bfs(i);
    int a = count(vis.begin(),vis.end(),true);
    no[i] = a;
    vis.clear();

    if(no[i] > f){
      f = no[i];
      i1=i;
    }
  }
  printf("Case %d: %d\n",cs,i1);
}



return 0;
}

