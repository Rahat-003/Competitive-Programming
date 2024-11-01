#include <bits/stdc++.h>
using namespace std;


int main(){

//freopen("tst.txt","r",stdin);

char c;
   cin.unsetf(ios::skipws);
int dgt = 0,ltr=0;
while(cin>>c){

  if(c=='\n' && ltr==0) {
      cout<<endl;
  continue;
  }
  ltr++;
  if(c=='\n') cout<<c;
  if(isdigit(c)) dgt+= c - '0';
  else if(c==' ')  continue;
  else if(c=='!') cout<<endl;
  else{
      for(int i=0;i<dgt;++i){
        if(c=='b')  cout<<" ";
  else cout<<c;

  }
    dgt = 0;
  }




}





return 0;
}
