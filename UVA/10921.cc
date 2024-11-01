#include <bits/stdc++.h>
using namespace std;


map<char,int> mp;

void func(char c,int d,int r){
  for(int i=0;i<r;++i)
    mp[c+i] = d;
}

int main(){

mp['0'] = 0;
mp['1'] = 1;
int n = 2;
for(int i=0;i<15;++i){
  if(i%3==0 && i) n++;
  mp['A'+i] = n;
}
func('P',7,4);
func('T',8,3);
func('W',9,4);

string s;
while(cin>>s){
  for(int i=0;i<s.size();++i){
    if(s[i]=='-') cout<<"-";
    else cout<<mp[s[i]];
  }
  cout<<endl;
}
/*
for(auto it = mp.begin(); it!=mp.end(); ++it)
  cout<<it->first<<" "<<it->second<<endl;
*/

return 0;
}
