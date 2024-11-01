#include <bits/stdc++.h>
using namespace std;

map<char,int>mp;

int digit(int a){
  int c=0;
  while(a){
    c+= a%10;
      a/=10;
  }
  if(c>=10) return digit(c);
  return c;
}

int main(){
// freopen("10424.txt","r",stdin);

for(int i=0;i<26;i++){
  mp['a'+i] = i+1;
  mp['A'+i] = i+1;
}
string s,t;
while(getline(cin,s) && getline(cin,t)){
  transform(s.begin(),s.end(),s.begin(),::tolower);
  transform(t.begin(),t.end(),t.begin(),::tolower);

  int r1=0,r2=0;

  for(int i=0;i<s.size();i++)
    r1+= mp[s[i]];
    r1 = digit(r1);
  for(int i=0;i<t.size();i++)
    r2 += mp[t[i]];
    r2= digit(r2);
    if(r1>r2)
      swap(r1,r2);
    cout<<fixed<<setprecision(2)<<(double)r1/(double)r2 * 100.0<<" %\n";
}


return 0;
}
