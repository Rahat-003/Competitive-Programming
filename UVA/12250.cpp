#include <bits/stdc++.h>
using namespace std;
int main(){
string s ;
string lan[] = {"HELLO","HOLA","HALLO","BONJOUR","CIAO","ZDRAVSTVUJTE"};
string cntry[] = {"ENGLISH","SPANISH","GERMAN","FRENCH","ITALIAN","RUSSIAN"};
int tc = 0;
while(cin>>s){
  if(s=="#")  break;
  int i=0;
  tc++;
  int f = 0;
  for(int i=0;i<6;i++){
    if(s==lan[i]){
        f=1;
      cout<<"Case "<<tc<<": "<<cntry[i]<<endl;
      break;
    }
  }
  if(!f) cout<<"Case "<<tc<<": UNKNOWN"<<endl;
}

return 0;
}
