#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
//string s,t;

int lcs(int r, int c,string s,string t){

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

int main(){
string s,t;
int tc = 0;
while(getline(cin,s)){
  if(s=="#")  break;
  getline(cin,t);
  int sz = s.size()+1;
  int tz = t.size()+1;
  v.assign(sz,vector<int> (tz,0) );



int ans = lcs(sz,tz,s,t);
  //print(sz,tz);

  printf("Case #%d: you can visit at most %d cities.\n",++tc,ans);

for(int i=0;i<v.size();++i)
  v[i].clear();

}

return 0;
}
