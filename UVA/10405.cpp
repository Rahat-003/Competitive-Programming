
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
string s,t;

int lcs(int r, int c){

  int ans = 0;

  for(int i=1;i<r;++i){
    for(int j=1;j<c;++j){
      char x = s[i-1];
      char y = t[j-1];
    if(x==y)  v[i][j] = 1 + v[i-1][j-1];
    else v[i][j] = max(v[i-1][j],v[i][j-1]);
    if(ans<v[i][j]) ans = v[i][j];
    }
  }
    return ans;
}
void print(int r,int c){
  for(int i=0;i<r;++i){
    for(int j=0;j<c;++j)
      cout<<v[i][j]<<" ";
    cout<<endl;
  }
}

int main(){


while( getline(cin,s) && getline(cin,t) ){

int sz = s.size()+1, tz = 1+t.size();
v.assign(sz,vector<int> (tz,0) );



int ans = lcs(sz,tz);
  //print(sz,tz);

cout<<ans<<endl;

for(int i=0;i<v.size();++i)
  v[i].clear();
}
return 0;
}
