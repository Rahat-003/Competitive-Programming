#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dec(string a){

  int sz = a.size()-1;
  int ans = 0;
  for(int i=0;i<a.size();++i){
    ans += (a[i] - '0') * pow(2,sz-i);
  }
  return ans;
}

int main(){

string  a;

while(getline(cin,a)){

  string s = "";
  for(int i=0;i<a.size();++i){
    char c = a[i];
    if(c==' ')  s.push_back('0');
    if(c=='o')  s.push_back('1');
  }

  if(s.size()){
    int x = dec(s);
    char c = x;
    if(x==10) cout<<endl;
    else cout<<c;
  }
}


return 0;
}



