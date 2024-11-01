#include <bits/stdc++.h>
using namespace std;

int main(){
string s;
int tc=0;
while(cin>>s){
  if(s=="*")  break;
  tc++;
  if(s=="Hajj") cout<<"Case "<<tc<<": Hajj-e-Akbar"<<endl;
  if(s=="Umrah") cout<<"Case "<<tc<<": Hajj-e-Asghar"<<endl;
}

return 0;
}
