#include <bits/stdc++.h>
using namespace std;


int main(){
string s,t;
while(getline(cin,s)){
  int m=0,n=0;
  for(int i=0;i<s.size();++i){
    if(s[i]==' ' || i==s.size()-1){
        if(i==s.size()-1) n = 1;
      for(int j=i-1+n;j>=m;j--)
        cout<<s[j];
  if(!n)    cout<<" ";
      m = i+1;
    }
  }
cout<<endl;
}






return 0;
}
