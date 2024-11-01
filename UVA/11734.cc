#include <bits/stdc++.h>

using namespace std;

int check(string s,string t){
  if(s==t)  return 1;
  string a,b;
  for(int i=0;i<s.size();++i)
    if(s[i]!=' ') a.push_back(s[i]);

  for(int i=0;i<t.size();++i)
    if(t[i]!=' ') b.push_back(t[i]);


  if(a==b) return 2;

  else return 0;

}


int main(){


int t;
cin>>t;
cin.ignore();
for(int tc = 1;tc<=t;++tc){
  string s,t;
  getline(cin,s);
  getline(cin,t);

  printf("Case %d: ",tc);

  if(!check(s,t)) puts("Wrong Answer");
  else if(check(s,t)==1)  puts("Yes");
  else puts("Output Format Error");


}







return 0;
}
