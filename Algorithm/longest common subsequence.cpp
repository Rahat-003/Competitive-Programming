#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > v;

vector<bool> S,T;
string s,t,e;
int o=0;
int lcs(int r,int c){

  int ans = 0;

  int jj=0,ii=0;
  for(int i=1;i<r;++i){
    for(int j=1;j<c;++j){
      char c = t[i-1];
      char d = s[j-1];
        if(c==d){
          v[i][j] = 1 + v[i-1][j-1];
      if(j>jj){
          jj=j; ii=i;
        e.push_back(c);
      T[i-1] = true ;
      S[j-1] = true;
      }
        }
        else  v[i][j] = max( v[i-1][j],v[i][j-1] );
      o++;
        if(v[i][j]>ans) ans = v[i][j];
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
cin>>s>>t;
int sz = s.size()+1, tz = t.size()+1;

///string s aligned to column
///string t aligned to row

v.assign(tz,vector<int>(sz,0));

S.assign(s.size(), false);
T.assign(t.size(), false);

int ans = lcs(tz,sz);

  //print(tz,sz);

cout<<ans<<endl;
//cout<<o<<endl;

cout<<e<<endl;

return 0;
}
