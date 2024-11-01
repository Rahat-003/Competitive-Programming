#include <bits/stdc++.h>
using namespace std;
map<char,int> mp;

int main(){

int t;
cin>>t;
cin.ignore();
while(t--){
  string s;
  getline(cin,s);
  for(int i=0;i<s.size();++i){
    char c = s[i];
    int d = c;
    if(d>=65 && d<=90)
      c = c+32;

    d = c;
    if(d>=97 && d<=122){
      mp[c]++;
    }
  }
  int x=-1;
  string ans;
  for(auto it = mp.begin();it!=mp.end(); ++it)
    if(x < it->second)
      x = it->second;

  for(auto it = mp.begin(); it!=mp.end(); ++it)
    if(it->second==x)
      ans.push_back(it->first);

  cout<<ans<<endl;
  mp.clear();
}

return 0;
}
