#include <bits/stdc++.h>
using namespace std;

int main(){
string s;

string m;
while(getline(cin,s)){
int cnt=0;

  for(int i=0;i<s.size();i++){
  if(s[i]=='"'){
    m = s.substr(i+1);
    s.erase(i);
    cnt+=1;
    if(cnt&1) s+="``";
    else s+="''";
  }
  }
  cout<<s<<endl;
}


return 0;
}
