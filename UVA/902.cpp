#include <bits/stdc++.h>
using namespace std;


int main(){
int x;
string y;
while(cin>>x>>y){
  map<string,int> mp;
  for(int i=0;i<=y.size()-x; ++i){
    string s = y.substr(i,x);
    mp[s]++;
  }
  string ans;
  int fl = -1;
  for(auto it=mp.begin();it!=mp.end();++it){
    if(it->second > fl){
      fl = it->second;
      ans = it->first;
    }
  }
  cout<<ans<<endl;
}

return 0;
}
