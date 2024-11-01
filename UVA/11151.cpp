#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mx 1003
  string s,t;
vector<vector<int>> v;

int lcs(int x,int y){
  if(x==s.size() || y==t.size())  return 0;
  if(v[x][y]!= -1) return v[x][y];

  if(s[x]==t[y]){
    v[x][y] = 1+lcs(x+1,y+1);
  }
  else{
    v[x][y] = max( lcs(x,y+1),lcs(x+1,y) );
  }
  return v[x][y];
}


int main(){


int tc;
cin>>tc;
cin.ignore();
while(tc--){
  getline(cin,s);
  t = s;
  v.assign(s.size(),vector<int>(s.size(),-1));
  reverse(t.begin(),t.end());

  if(!s.size()){
    cout<<0<<endl;
    continue;
  }

  int ans = lcs(0,0);
  cout<<ans<<endl;

  for(int i=0;i<v.size();++i)
    v[i].clear();

}





return 0;
}
