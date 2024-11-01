/*
///Eta vul
#include <bits/stdc++.h>
using namespace std;
map<string,vector<string>> mp;
map<string,bool> vis;
unordered_map<string,int> par;
void clr(){
  vis.clear();  mp.clear(); par.clear();
}

void dfs(string s){
  if(par[s]==0){
      cout<<s<<" ";
    vis[s] = true;
    for(int i=0;i<mp[s].size();++i){
      string child = mp[s][i];
      par[child]--;
      if(!vis[child])
        dfs(child);
    }
  }
}

int main(){
  freopen("print.txt","w",stdout);
int n,tc=0;
  while(cin>>n){
      tc++;
    for(int i=0;i<n;++i){
      string s;
      cin>>s;
      vis[s] = false;
      par[s] = 0;
    }
    int e;  cin>>e;
    while(e--){
      string a,b;
      cin>>a>>b;
      mp[a].push_back(b);
      par[b]++;
    }
    printf("Case #%d: Dilbert should drink beverages in this order: ",tc);
    for(auto it = par.begin();it!=par.end();++it){
      if(!vis[it->first])
        dfs(it->first);
    }
    cout<<'\b'<<".\n\n";
    clr();
  }

return 0;
}

*/



#include <bits/stdc++.h>
using namespace std;



int main(){

int n;

int tc = 0;

while(cin>>n){

  vector<string> v;
  vector<bool> vis;
  vector<int> indeg;
  vis.assign(n+1,false);
  indeg.assign(n+1,0);

  map<string,int> mp;
  map<string,vector<string> > np;
  map<int,string> op;

  for(int i=1;i<=n;i++){
    string m;
    cin>>m;
    v.push_back(m);
    mp[m] = i;
    op[i] = m;
  }

  int e;
  cin>>e;
  while(e--){
    string a,b;
    cin>>a>>b;
    np[a].push_back(b);
    int w = mp[b];
    indeg[w]++;
  }

  int id = 1;
  printf("Case #%d: Dilbert should drink beverages in this order:",++tc);

  while(id<=n){
  int u = 1;


  while( u<=n && ( vis[u] || indeg[u] ) ) u++;
    vis[u] = true;
  cout<<" "<<op[u];
  id++;
  string s = op[u];
  for(auto it = np[s].begin(); it!=np[s].end(); it++){
    string child = *it;
    int ii = mp[child];
    indeg[ii]--;

  }
}
cout<<"."<<endl<<endl;



}

return 0;
}

/**

Etao hoy

#include <bits/stdc++.h>
using namespace std;

  vector<string> v;
  map<string,bool> vis;
map<string,vector<string>> mp;
map<string,int> indeg;
  vector<string> ans;

  void decrement(string s){
    for(int i = 0; i<mp[s].size();i++){
      string w = mp[s][i];
      indeg[w]--;
    }

  }
  int tc = 0;
void top_sort(){

  int cnt = 0;
  while(cnt<=v.size()){
  bool fl = false;

  for(int i=0;i<v.size();i++){
   string m = v[i];
    if(indeg[m] ==0 && !vis[m]){
      ans.push_back(m);
      vis[m] = true;
     decrement(m);
    fl = true;
    }
    if(fl)  break;
  }
//  cout<<"infinite\n";
     cnt++;

//  break;
  }
  printf("Case #%d: Dilbert should drink beverages in this order:",++tc);

for(int i=0;i<ans.size(); i++)
  cout<<" "<<ans[i];
cout<<"."<<endl<<endl;

}

int main(){

freopen("tst.txt","r",stdin);
freopen("txt.txt","w",stdout);

int n;

while(cin>>n){

  for(int i=0;i<n;i++){
    string a; cin>>a;
    v.push_back(a);
    vis[a] = false;
  }
  int e;
  cin>>e;
  while(e--){
    string a,b;
    cin>>a>>b;
    mp[a].push_back(b);
    indeg[b]++;
  }
  top_sort();

v.clear();
vis.clear();
mp.clear();
indeg.clear();
ans.clear();
}


return 0;
}

*/

