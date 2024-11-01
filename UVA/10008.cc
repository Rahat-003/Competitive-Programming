#include <bits/stdc++.h>
using namespace std;
map<char,int> mp;
typedef pair<int,char> pp;

struct node{
  int dd;
  char cc;


  node(int x =0, char y='0'){
    dd = x;
    cc = y;
  }

  bool operator<(const node& n1) const {
    if(dd>n1.dd) return true;
    if(dd==n1.dd && cc<n1.cc) return true;
    return false;
  }
};



int main(){
for(int i=0;i<26;++i){
  mp['A'+i] = 0;
}

int t;
cin>>t;
cin.ignore();
while(t--){
  string s;
  getline(cin,s);
  for(int i=0;i<s.size(); ++i){
    char c = s[i];
    int d = c;
    if(d>=65 && d<=90)
      mp[c]++;
    else if(d>=97 && d<=122)
      mp[c-32]++;
  }
}
  vector<node> v;

  for(auto it = mp.begin(); it!=mp.end();++it){
    if (it->second !=0)
      v.push_back(node(it->second,it->first));
  }

  sort(v.begin(),v.end());
  for(int i=0;i<v.size();++i)
    cout<<v[i].cc<<" "<<v[i].dd<<endl;





return 0;
}
