#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> mp;

void bfs(int a,int b){

  map<int,bool>vis;
  queue<int> q;
  vis[a] = true;
  map<int,int> par;
  par[a] = -1;
  q.push(a);

      while(!q.empty()){
        int u= q.front();
        q.pop();
        for(int i=0; i<mp[u].size(); i++){
          int child = mp[u][i];
          if(!vis[child]){
            vis[child] = true;
            par[child] = u;
            q.push(child);
          }
          if(child == b)  break;
        }
      }
      vector<int> v;
      int bb=b;
      if(!vis[b])
        cout<<"connection impossible";
      else{
  while(1){
      if(bb==-1)  break;
    v.push_back(bb);
    bb=par[bb];
  }
  for(int i=v.size()-1; i>=0; i--)
  if(i>0) cout<<v[i]<<" ";
   else cout<<v[i];
}
}
int main(){
  freopen("627.txt","r",stdin);
int n;
while(cin>>n){
  int t=n;
  cout<<"-----\n";
while(n--){
  string s;
 if(n==t-1) cin.ignore();
  getline(cin,s);
  int i1=s.find('-');
  int a = atoi( (s.substr(0,i1) ).c_str() );
  s.push_back(',');
  int f=i1+1;
  for(int i=i1+1; i<s.size();i++){
      string ss; int b;
      if(s[i]== ','){
        ss= s.substr(f,i);
        f=i+1;
        b = atoi(ss.c_str());
        mp[a].push_back(b);
    }
  }
}
  int m;  cin>>m;
  while(m--){
    int x,y;  cin>>x>>y;
    bfs(x,y);
    cout<<endl;
  }
  mp.clear();

}
return 0;
}
