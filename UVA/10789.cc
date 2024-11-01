#include <bits/stdc++.h>
using namespace std;
#define mx 2003
vector<bool> vis(mx);
//int cnt=0;
map<char,int> mp;

void sieve(){
  for(int i=0;i<vis.size();i+=2){
    vis[i] = true;
  }
  vis[2] = false;
  vis[1] = true;
  for(int i=3;i*i<=mx;i+=2){
    if(!vis[i]){
    for(int j=2*i;j<mx; j+=i)
      vis[j] = true;
  }
}
}

int main(){
fill(vis.begin(),vis.end(),false);
sieve();
int t;
cin>>t;
cin.ignore();
for(int tc=1;tc<=t;++tc){
  string s;
  getline(cin,s);
  for( int i=0;i<s.size(); ++i ){
    char c = s[i];
    mp[c]++;
  }
  string ans="";
  for(auto it=mp.begin();it!=mp.end();++it)
    if(!vis[it->second])
      ans.push_back(it->first);

  if(!ans.size()) ans = "empty";
  printf("Case %d: ",tc);
    cout<<ans<<endl;
  mp.clear();
}

return 0;
}
