#include <bits/stdc++.h>
using namespace std;


string wave(int n){
  string s,t;
  stringstream ss;
  ss<<n;
  s = ss.str();
  for(int i=0;i<n;++i)
    t.append(s);
  return t;
}


int main(){

int t;
cin>>t;
while(t--){
  int a,f;
  cin>>a>>f;
  if(a>9) a=9;
  string w;
  for(int i=1;i<=a;++i){
    w.append(wave(i));
    w.push_back('\n');
  }
  for(int i=a-1;i>0;--i){
    w.append(wave(i));
    w.push_back('\n');
  }
  for(int i=0;i<f;++i){
    cout<<w;
    if(i!=f-1)  cout<<endl;
  }
  if(t!=0)cout<<endl;
}





return 0;
}
