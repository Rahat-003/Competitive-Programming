#include <bits/stdc++.h>
using namespace std;

int main(){
string s;
  int c=0;
while(getline(cin,s)){
  string t = "";
  for(int i=0;i<s.size();i++){
    if(s[i]=='"'){
      c+=1;
      if(c&1) t += "``";
      else t+= "''";
      }
    else t.push_back(s[i]);
  }
  cout<<t<<endl;
  t="";
}


return 0;
}
