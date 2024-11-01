#include <bits/stdc++.h>
using namespace std;

map<char,int> mp;
map<char,bool> vis;
vector<vector<int>> v;
vector<bool> viss;

int id = -1;

void make(char c,char d){
  if(!vis[c]){
    vis[c] = true;
    id++;
    mp[c] = id;
  }
  if(!vis[d]){
    vis[d] = true;
    id++;
    mp[d] = id;
  }
  int x = mp[c],
      y = mp[d];
  v[x].push_back(y);
  v[y].push_back(x);

}

void dfs(int a){
  viss[a] = true;
  for(int i=0;i<v[a].size(); i++){
      int child = v[a][i];
    if(!viss[child])
      dfs(child );
  }
}


int main(){
  //freopen("tst.txt","r",stdin);

int t;
cin>>t;
bool fl = false;
while(t--){

  if(fl) cout<<endl;

  id = -1;
  char r;
  cin>>r;
  int R = r - 'A' + 1;
  v.assign(R,vector<int>());
  viss.assign(R,false);

  string s;
  cin.ignore();
  while(getline(cin,s)){
    if(!s.size()) break;

    make(s[0], s[1]);
  }
  int cnt = 0;
  for(int i=0;i<R;i++){
    if(!viss[i]){
      dfs(i);
      cnt++;
    }
  }
  cout<<cnt<<endl;
fl = true;
mp.clear();
vis.clear();

}







return 0;
}
