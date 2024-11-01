#include <bits/stdc++.h>
using namespace std;
unordered_map<char,bool> vis;
typedef pair<int,char> pp;
vector<pp> x,y;

void make(string s, vector<pp>& v) {

  for(int i=0;i<s.size(); i++){
    char c = s[i];
    if(!vis[c]){
      int cnt = count(s.begin(),s.end(),c);
      v.push_back(pp(cnt,c));
      vis[c] = true;
    }
  }
  vis.clear();
  sort(v.begin(),v.end());
}

int main(){
//freopen("tst.txt","r",stdin);

int t;
cin>>t;
bool fl = false;

while(t--){

  string s,t;
  cin>>s>>t;

  make(s,x);
  make(t,y);
  map<char,char> mp;
  if(fl)  cout<<endl;
  fl = true;
  for(int i=0;i<x.size(); i++){
    char c = x[i].second;
    char d = y[i].second;
    mp[d] = c;
  }
  for(int i=0;i<t.size(); i++)
    cout<<mp[ t[i] ];
  cout<<endl;
  x.clear();
  y.clear();

}





return 0;
}
