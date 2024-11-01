#include <bits/stdc++.h>
using namespace std;

  vector<char> plain,subs;
char func(char c){
  for(int i=0;i<plain.size();++i){
    if(plain[i]==c)
      return subs[i];
  }
  return c;
}

int main(){
//  freopen("tst.txt","r",stdin);
int t;
cin>>t;
cin.ignore();
cin.ignore();
bool fl = false;
while(t--){

  string p,sb,s;
  getline(cin,p);
  getline(cin,sb);
  if(fl)  cout<<endl;
  fl = true;
  for(int i=0;i<p.size();++i){
    plain.push_back(p[i]);
    subs.push_back(sb[i]);
  }
  string ans;
  while(getline(cin,s)){
    if(s.size()==0) break;
  for(int i=0;i<s.size();++i){
    ans.push_back(func(s[i]));

  }
  ans.push_back('\n');
  }
  cout<<sb<<endl<<p<<endl;
  cout<<ans;
  plain.clear();  subs.clear();
}







return 0;
}
