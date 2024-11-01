#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
  string s,t;

int lcs(int r,int c){
  int ans = 0;
  for(int i=1;i<r;++i){
    for(int j=1;j<c;++j){
      char c = s[i-1];
      char d = t[j-1];
      if(c==d)  v[i][j] = 1 + v[i-1][j-1];
      else v[i][j] = max( v[i-1][j],v[i][j-1] );
      if(ans<v[i][j]) ans = v[i][j];
    }
  }
  return ans;
}

int main(){

int r,c;
int tc = 0;

while(cin>>r>>c){

  if(!r && !c)  break;
  unordered_map<int,char> mp;
  int cnt=0;
  s="",t="";
  for(int i=0;i<r;++i){
    int a;  cin>>a;
    if(!mp[a]) {
      mp[a] = 'A' + cnt;
      cnt++;
    }
    s.push_back(mp[a]);
  }
  for(int i=0;i<c;++i){
    int a;  cin>>a;
    if(!mp[a]) {
      mp[a] ='A'+ cnt;
      cnt++;
    }
    t.push_back(mp[a]);
  }
//  cout<<s<<endl<<t<<endl;
  v.assign(r+1,vector<int> (c+1,0) );
  int ans = lcs(r+1,c+1);

  //if(tc)

  printf("Twin Towers #%d\nNumber of Tiles : %d\n",++tc,ans);
  cout<<endl;
  for(int i=0;i<v.size();++i)
    v[i].clear();

}
return 0;
}
