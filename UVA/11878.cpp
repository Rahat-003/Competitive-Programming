#include <bits/stdc++.h>
using namespace std;
vector<string> v;




int calc(string s){

  if(s[s.size()-1]=='?')  return 0;

  char c;
  string x,y,z;
  int i;
  for( i=0;i<s.size();++i){
      int r = s[i] - '0';
    if(r>=0 && r<10)  x.push_back(s[i]);
    else {
      c = s[i]; break;
    }
  }
  for(i = i+1;i<s.size();++i){
      int r = s[i] - '0';
    if(r>=0 && r<10)  y.push_back(s[i]);
    else {
      break;
    }
  }
  for(i = i+1;i<s.size();++i){
      int r = s[i] - '0';
    if(r>=0 && r<10)  z.push_back(s[i]);
    else {
      break;
  }
}
  int p,q,r;
  p = atoi(x.c_str());
  q = atoi(y.c_str());
  r = atoi(z.c_str());

//  cout<<x<<" "<<y<<" "<<z<<endl;

  if(c=='+' && p+q==r)  return 1 ;
  if(c=='-' && p-q==r)  return 1;

  return 0;
}



int main(){

string s;
while(getline(cin,s)){
  if(!s.size()) break;
  v.push_back(s);
}
int ans=0;

/*
for(int i=0;i<v.size();++i)
  cout<<v[i]<<endl;
cout<<calc(v[0]);
*/

for(int i=0;i<v.size();++i)
  ans+= calc(v[i]);


cout<<ans<<endl;


/*
*/

return 0;
}
