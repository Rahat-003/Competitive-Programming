#include <bits/stdc++.h>
using namespace std;

int main(){

int t;
cin>>t;
  cin.ignore();
while(t--){
    string s;
  getline(cin,s);
  int sz = s.size();
  int x = sqrt(sz);
  if(x*x!=sz) {
    puts("INVALID");
    continue;
  }
  vector<vector<char>> v;
  v.assign(x,vector<char>(x,' '));
  int i1=0;
  for(int i=0;i<x;++i){
    for(int j=0;j<x;++j){
      v[i][j] = s[i1];
      i1++;
    }
  }
  for(int i=0;i<v.size();++i){
    for(int j=0;j<v[i].size();++j)
      cout<<v[j][i];
  }
    cout<<endl;


}





return 0;
}
