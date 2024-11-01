#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;

int main(){
int t;
cin>>t;
cin.ignore();
while(t--){
  string s,t;
  cin>>s;
  getline(cin,t);
  mp[s]++;
}
for(auto it=mp.begin();it!=mp.end();++it)
  cout<<it->first<<" "<<it->second<<endl;

return 0;
}
