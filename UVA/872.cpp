
#include <bits/stdc++.h>
using namespace std;

map<char,int> mp;
map<int,char> ic;

vector<bool> vis,visited1,visited2;
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
  visited1.clear();
  visited2.clear();
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

bool dfs(int a){
  if(!visited1[a]){
  visited1[a] = true;
  visited2[a] = true;
  for(int i=0;i<v[a].size(); i++){
    int child = v[a][i];
    if(!visited1[child] && dfs(child))  return true;
    else if(visited2[child])  return true;
  }

  }

  visited2[a] = false;
  return false;

}

bool check(int n){
  for(int i=0;i<n;i++)
    if(dfs(i))  return true;

return false;
}


int main(){

//freopen("tst.txt","r",stdin);

string s;

bool flag = false;

int t;
cin>>t;
cin.ignore();
cin.ignore();
while(t--){

      if(flag)  cout<<endl;
      flag = true;
      string s;

      getline(cin,s);

    char c;
    istringstream iss(s);
    int id = -1;
    while(iss>>c){
      mp[c] = ++id;
      ic[id] = c;
    }
  vis.assign(id+1,false);
  visited1 = vis;
  visited2 = vis;
  v.assign( id+1,vector<int>() );
  indeg.assign(id+1,0);

  string t;
  getline(cin,t);
  char x,y,gar;
  istringstream jss(t);

  while(jss>>x>>gar>>y){
    int m = mp[x];
    int n = mp[y];
  v[m].push_back(n);
  indeg[n]++;
  }

    if(check(id+1)){
      puts("NO");
      clr();
      continue;
    }


  top_sort(id+1);
  sort(ans.begin(),ans.end());

  for(int i=0;i<ans.size(); i++){
    string m = ans[i];
    for(int j=0;j<m.size(); j++){
      if(j) cout<<" ";
      cout<<m[j];
    }
    cout<<endl;
  }


clr();
cin.ignore();

}


return 0;
}


