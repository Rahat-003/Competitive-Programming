#include <bits/stdc++.h>
using namespace std;
//map<string,int> mp;
int main(){
  /*
  mp["MM"] =0;
  mp["FF"] =0;
  mp["MF"] =0;
  mp["FM"] =0;*/
  int tc;
  cin>>tc;
  while(tc--){
      string s;
      cin.ignore();
      getline(cin,s);
      int p=0,f1=1;
      for(int i=1; i<s.size();i++){
        if(s[i]==' ') continue;
        if(s[p]!=s[i]){
          f1=1; break;
        }
      }
  }





return 0;
}
