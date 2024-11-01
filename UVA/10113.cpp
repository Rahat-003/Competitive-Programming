#include <bits/stdc++.h>
using namespace std;

map<string,vector<pair<string,pair<int,int>>> > mp;

map<string,bool> vis;

void bfs(string s, string d){

vis[s] =true;

map< string, pair< string,pair<int,int>> > par;

map<string,string> par1;

queue<string> q;

q.push(s);
  while(!q.empty()){
    string u = q.front();
    q.pop();
    for(int i=0;i<mp[u].size();i++){
      string child = mp[u][i].first;
      if(!vis[child]){
          int x = mp[u][i].second.first;
        int y = mp[u][i].second.second;
        vis[child] = true;
        q.push(child);
       par[child] = {u, {x,y} };
      par1[child] = u;
      }
      if(child == d)  break;
    }
  }
  string tmp = d;
  /*
  vector<pair<string,string>> v;
  vector<pair<int,int>> vv;
  */
  int x=1,y=1;
if(vis[d]){
      while(1){
      int a = par[tmp].second.first;
      int b = par[tmp].second.second;
/*    v.push_back({par1[tmp], tmp});
    vv.push_back({a,b});
*/  x *=a;  y *=b;
    tmp = par1[tmp];
    if(tmp==s)  break;
  }
int w = __gcd(x,y);
cout<<x/w<<" "<<s<<" = "<<y/w<<" "<<d<<endl;
}
else cout<<"?"<<" "<<s<<" = "<<"?"<<" "<<d<<endl;
  for(auto it=vis.begin();it!=vis.end();it++)
    vis[it->first] = false;
}

int main(){
  freopen("10113.txt","r",stdin);

string c1,c2;
int i1,i2;
char c;
while(cin>>c){
    if(c=='.')  break;
    char eq;
if(c=='!'){
    cin>>i1>>c1>>eq>>i2>>c2;
    int gcd = __gcd(i1,i2);
  mp[c1].push_back({c2,{i1/gcd,i2/gcd}});
  mp[c2].push_back({c1,{i2/gcd,i1/gcd} });
  vis[c1] = false;
  vis[c2] = false;
}

if(c=='?'){
  string s,d;
  cin>>s>>eq>>d;
  bfs(s,d);
}

}

return 0;
}


