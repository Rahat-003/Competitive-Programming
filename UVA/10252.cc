#include <bits/stdc++.h>
using namespace std;

int main(){

  ///getline e neya lagbe. coz blank line o ekta string hote pare
string s,t;
while(getline(cin,s)){
  getline(cin,t);
  map<char,int> mp1,mp2;
  for(int i=0;i<s.size();++i){
    mp1[s[i]]++;
  }
  for(int i=0;i<t.size();++i)
    mp2[t[i]]++;

  string ans;
  for(int i=0;i<26;++i){
    char c = 'a'+i;
    if( mp1[c] && mp2[c] ){
      int w = min(mp1[c],mp2[c]);

      for(int i=0;i<w;++i)
        ans.push_back(c);
    }
  }
  cout<<ans<<endl;
}

return 0;
}

