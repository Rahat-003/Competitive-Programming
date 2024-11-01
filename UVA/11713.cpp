#include <bits/stdc++.h>
using namespace std;

bool check(string s,string t){
  if(s.size()!=t.size())  return false;
  string vowel = "aeiou";

  for(int i=0;i<s.size();++i){
    char c = s[i];
    auto it = find(vowel.begin(),vowel.end(),c);
    if( it==vowel.end() && s[i]!=t[i])  return false;

  }
return true;
}


int main(){
int t;
cin>>t;
while(t--){
  string s,t;
  cin>>s>>t;
  if(check(s,t))
    puts("Yes");
  else puts("No");

}

return 0;
}
