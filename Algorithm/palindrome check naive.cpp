#include <bits/stdc++.h>
using namespace std;


bool pal(string s){
  int sz = s.size(),  hf = sz/2;
    for(int i=0;i<hf;++i){
      if(s[i]!=s[sz-1-i])   return false;
    }
    return true;
}

int main(){

string s;
while(cin>>s)
  if(pal(s))  cout<<"palindrome\n";
else cout<<"Simple\n";





return 0;
}
