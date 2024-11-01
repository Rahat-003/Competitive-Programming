#include <bits/stdc++.h>
using namespace std;
string s = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?" , t,ans;
char f(char c){
  if(c==' ') return c;
  for(int i=0;i<s.size();++i)
    if(s[i]==c)
      return s[i-2];
}
int main(){
getline(cin,t);
for(int i=0;i<t.size();++i){
  ans.push_back(f(t[i]));
}
cout<<ans<<endl;



return 0;
}
