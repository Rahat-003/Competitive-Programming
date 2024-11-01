#include <bits/stdc++.h>
using namespace std;

bool check(string a){
  char c = a[a.size()-1];
  int j = a.size()-1;
//  if(c=='.' || c==',' || c=='!' || c=='?')  j--;

  int lmt = j;
  for(int i=0;i<lmt;++i){
    if(a[i]!=a[j])
      return false;
    j--;
  }
  return true;

}

int main(){

string s;

while(getline(cin,s)){
  if(s=="DONE") break;
  string tmp="";
  for(int i=0;i<s.size();++i){
    if(s[i]=='.' || s[i]==',' || s[i]=='!' || s[i]=='?' || s[i]==' ')
    continue;
      tmp.push_back(s[i]);
  }
  transform(tmp.begin(),tmp.end(),tmp.begin(),::tolower);
  if(check(tmp))
    cout<<"You won't be eaten!"<<endl;
  else cout<<"Uh oh.."<<endl;

}





return 0;

}
