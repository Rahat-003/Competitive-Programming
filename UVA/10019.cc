#include <bits/stdc++.h>
using namespace std;


int bin(int b){
  string m;
  while(b!=0){
    m.push_back( b%2 + '0');
    b/=2;
  }
  int aa = 0;
  for(int i=0;i<m.size();++i)
    if(m[i]=='1')
      aa++;

    return aa;

}
int to_hexa(string s){
  int m = 0;
  for(int i=0;i<s.size();++i){
    m+= (s[i] - '0') * pow(16,s.size()-1-i);
  }
  return m;
}



int main(){
int t;
cin>>t;
while(t--){
  int a;
  cin>>a;
  int ans1 = bin(a);
  string s; stringstream ss;
  ss<<a;
  s = ss.str();
  int b = to_hexa(s);
//  cout<<b<<endl;
  int ans2 = bin(b);
  cout<<ans1<<" "<<ans2<<endl;
}





return 0;
}
