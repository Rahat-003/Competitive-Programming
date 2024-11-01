#include <bits/stdc++.h>
using namespace std;
vector<char> num;
string f(string s){
  string w;
  for(int i=0;i<s.size();++i)
    if(s[i]!=' ') w.push_back(s[i]);
  return w;
}

bool check(string s){
  for(int i=0;i<s.size()-1;++i){
    if(s[i]!=' ' && s[i+1]==' ' && i+1!=s.size()-1)  return false;
  }
  return true;
}

bool recheck(string t){
  string s = " ";
  s+=t;
  s.push_back(' ');
  auto it = find(s.begin(),s.end(),'e');
  auto jt = find(s.begin(),s.end(),'E');

  for(int i=1;i<s.size()-1;++i){
    if(s[i]=='.' && (s[i-1]==' '||s[i+1]==' ') )
  }
}

int main(){
string s,p;
for(int i=0;i<=9;++i)
  num.push_back('0' + i);

while(getline(cin,s)){
  if(s=="*")  break;
  string q=f(s);
  s.push_back(' ');
  bool fl = true,fll = true;
  if(check(s)){
    fll = recheck(q);
  }
}





return 0;
}
