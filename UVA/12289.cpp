#include <bits/stdc++.h>
using namespace std;

int main(){
int tcc;
cin>>tcc;
string o ="one";
string t = "two";
string th = "three";
while(tcc--){
  string s;
  cin>>s;
  if(s.size()==5) cout<<"3";
else{
  int oc = 0, tc =0, thc=0;
    for(int i=0;i<s.size();i++){
      if(o[i]!=s[i])  oc+=1;
      if(t[i]!=s[i]) tc+=1;
    }
  if(oc==1 || oc==0)  cout<<"1";
  if(tc==1 || tc==0)  cout<<"2";
}


  cout<<endl;
}

return 0;
}
