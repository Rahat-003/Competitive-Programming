#include <bits/stdc++.h>
using namespace std;
struct node{
  int a;
  int b;
  node(int q=0,int w=0){
  a=q;
  b=w;
  }
  bool operator<(const node &n1) const{
    if(b<n1.b)  return true;
    if(b==n1.b && a>n1.a) return true;
    return false;
  }

};


int main(){

string s;
bool fl = false;
while(getline(cin,s)){
  if(fl) cout<<endl;
  fl = true;
  vector<node> v;
  map<int,int> mp;
  for(int i=0;i<s.size();++i){
    int x = s[i];
    mp[x]++;
  }
  for(auto it=mp.begin();it!=mp.end();++it){
    v.push_back(node(it->first,it->second));
  }
  sort(v.begin(),v.end());
  for(int i=0;i<v.size();++i)
    cout<<v[i].a<<" "<<v[i].b<<endl;
}




return 0;
}
