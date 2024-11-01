#include <bits/stdc++.h>
using namespace std;

bool check(string s,string p,int x,int y){

  for(int i=x, j=y; i<s.size(); ++i,++j)
    if(s[i]!=p[j])  return false;

return true;

}


int f(string s, string p){

  if(s==p)  return 0;

  int sz = s.size()-1,
      pz = p.size()-1;

  int j = 0,i;

  for( i=0; i<s.size(); ++i){
    if(s[i]==p[j] && s[sz]==p[j+sz-i]){
      if(check(s,p,i,j)) return i;

    }

  }
  return pz+1;

}


int main(){


int t;
cin>>t;
while(t--){
  int m,n;
  cin>>m>>n;
  vector<string> v;

  while(n--){
    string s;
    cin>>s;
    v.push_back(s);
  }

  int ans = v[0].size();

  for(int i=1;i<v.size();++i){
    string s = v[i-1];
    string p = v[i];
    ans += f(s,p);
  }

  cout<<ans<<endl;
}
return 0;
}
