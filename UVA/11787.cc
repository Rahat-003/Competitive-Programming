
#include <bits/stdc++.h>
using namespace std;

string m = "ABUSPFTM",n;
int num[]= {0,1,10,100,1000,10000,100000,1000000};
map<char,int> mp;
int ind(char c){
  for(int i=0;i<m.size();++i)
    if(m[i]==c)
      return num[i];
}

bool check(string s){
  vector<char> v;
  for(int i=0;i<s.size()-1;++i){
    if(s[i]!=s[i+1])
      v.push_back(s[i]);
  }

    int j,k;
  for(j=1;j<v.size();++j){
    if(mp[v[j-1]] < mp[v[j]] )
      continue;
    else break;
  }
  for(k=1;k<v.size();++k){
    if(mp[v[k-1]] > mp[v[k]] )
      continue;
    else break;
  }

  if(j==v.size() || k==v.size())  return true;

  return false;
}

int main(){

for(int i=0;i<m.size();++i)
  mp[m[i]] = num[i];

int t;
cin>>t;
while(t--){
  string s;
  cin>>s;
  s.push_back('A');
  int cnt=1;
  bool k = check(s), o =true;
  int q=0;
  if(k){
  for(int i=0;i<s.size()-1;++i){

    if(s[i]!=s[i+1])    cnt=1;
    else cnt++;

    if (cnt>9){
      puts("error");
      o = false;
      break;
    }
    int x = ind(s[i]);
    q+= mp[s[i]];
  }
  q+= mp[s[s.size()-1]];
  if(o) cout<<q<<endl;
  }
  else puts("error");
}




return 0;
}
