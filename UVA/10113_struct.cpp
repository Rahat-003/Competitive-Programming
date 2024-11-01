#include <bits/stdc++.h>
using namespace std;
struct triple{
  string y;
  int m,n;
} tt;
map<string,vector<triple>> mp;
map<string,bool> vis;

void bfs(string s, string d){
  vis[s] = true;
  map<string,triple> par;
  queue<string> q;
  q.push(s);
  while(!q.empty()){
    string u =q.front();
    q.pop();
    for(int i=0;i<mp[u].size(); i++){
      string child = mp[u][i].y;
      if(!vis[child]){
          int x = mp[u][i].m;
          int y = mp[u][i].n;
        vis[child] = true;
        q.push(child);
        par[child] = {u,x,y};
      }
      if(child==d)  break;
    }
  }
  string tmp = d;
  int x=1,y=1;
  if(vis[d]){
    while(1){
      x *= par[tmp].m;
      y *= par[tmp].n;
      tmp = par[tmp].y;
      if(tmp==s)  break;
    }
    int w = __gcd(x,y);
    x/=w;  y/=w;
    cout<<x<<" "<<s<<" = "<<y<<" "<<d<<endl;
  }
  else cout<<"? "<<s<<" = ? "<<d<<endl;
  for(auto it = vis.begin(); it!=vis.end(); ++it)
    vis[it->first] = false;
}


int main(){
char c,eq;
int a,b;
string s,t;
while(cin>>c){
  if(c=='.')  break;
  if(c=='!'){
    cin>>a>>s>>eq>>b>>t;  vis[s] = false; vis[t] = false;
  int gcd = __gcd(a,b);
  mp[s].push_back( {t,a/gcd,b/gcd} );
  mp[t].push_back( {s,b,a} );
  }
  else {
    string s,d; cin>>s>>eq>>d;
    bfs(s,d);
  }
}


return 0;
}
