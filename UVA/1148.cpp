#include <bits/stdc++.h>
using namespace std;
map<int,vector<int>> mp;

void bfs(int s, int d){
  map<int,bool>vis;
  vis[s] = true;
  queue<int>q;
  q.push(s);
  map<int,int>par;
  par[s] = -1;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i=0;i<mp[u].size(); i++){
      int child = mp[u][i];
      if(!vis[child]){
        vis[child] = true;
        q.push(child);
        par[child] = u;

      }
      if(child==d)  break;
    }
  }
vector<int> v;
int dd = d;
while(1){
  if(par[dd]==-1) break;
  v.push_back(dd);
  dd=par[dd];
}
cout<<s<<" "<<d<<" "<<v.size()-1<<endl;

}

int main(){
  freopen("1148.txt","r",stdin);
  freopen("C:\users\user\desktop\ans.txt", "w", stdout);

int t;
cin>>t;
int tc=0;
while(t--){
  int n,z;  cin>>n;

  while(n--){

    int m,l;  cin>>m>>l;
    while(l--){
      int p;
      cin>>p;
      mp[m].push_back(p);
    }

  }
  int s,d;
  cin>>s>>d;
  if(tc>0) cout<<endl;
  tc++;
  bfs(s,d);
  mp.clear();
}



return 0;
}
