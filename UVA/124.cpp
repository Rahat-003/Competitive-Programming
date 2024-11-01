#include <bits/stdc++.h>
using namespace std;

map<char,int> mp;
map<int,char> ic;

vector<bool> vis;
vector<vector<int>> v;
vector<int> indeg;
vector<string> ans;
string one;

void clr(){
  mp.clear();
  vis.clear();
  for(int i=0;i<v.size(); i++)
    v[i].clear();
  indeg.clear();
  ans.clear();
  one.clear();
}


void top_sort(int n){

  bool fl = false;

  for(int i=0;i<n;i++){

  if(!vis[i] && indeg[i]==0){
    char c = ic[i];
    one.push_back(c);
    vis[i] = true;

    for(int j = 0;j<v[i].size(); j++){
      int child = v[i][j];
      indeg[child]--;
    }
    top_sort(n);
    vis[i] = false;
    for(int j = 0;j<v[i].size(); j++){
      int child = v[i][j];
      indeg[child]++;
    }
    one.erase(one.end() - 1);
    fl = true;
  }

  }
  if(!fl)
    ans.push_back(one);
}


int main(){

string s;

bool flag = false;

while(getline(cin,s)){

      if(flag)  cout<<endl;
      flag = true;

    char c;
    istringstream iss(s);
    int id = -1;
    while(iss>>c){
      mp[c] = ++id;
      ic[id] = c;
    }
  vis.assign(id+1,false);

  v.assign( id+1,vector<int>() );
  indeg.assign(id+1,0);
  string t;
  getline(cin,t);
  char x,y;
  istringstream jss(t);
  while(jss>>x>>y){
    int m = mp[x];
    int n = mp[y];
  v[m].push_back(n);
  indeg[n]++;
  }

  top_sort(id+1);
  sort(ans.begin(),ans.end());
  for(int i=0;i<ans.size(); i++)
    cout<<ans[i]<<endl;


clr();

}


return 0;
}



