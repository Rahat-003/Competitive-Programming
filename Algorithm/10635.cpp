#include <bits/stdc++.h>
using namespace std;
vector<int> s,t;
vector<vector<int>> v;

int lcs(int r,int c){
  int n = 0;
  for(int i=1;i<r;++i){
    for(int j=1;j<c;++j){
      if(s[i-1]==t[j-1])
        v[i][j] = 1 + v[i-1][j-1];
      else v[i][j] = max(v[i-1][j],v[i][j-1]);

      if(n<v[i][j]) n = v[i][j];
    }

  }
  return n;

}

int main(){
//  freopen("tst.txt","r",stdin);

int z;
cin>>z;
for(int tc=1;tc<=z;++tc){
  int xx,r,c;
  cin>>xx>>r>>c;
  r+=2; c+=2;
  v.assign(r,vector<int>(c,0));

  for(int i=1;i<r;++i){
    int a;
    cin>>a;
    s.push_back(a);
  }
  for(int i=1;i<c;++i){
    int a;
    cin>>a;
    t.push_back(a);
  }
  int ans = lcs(r,c);

  printf("Case %d: %d\n",tc,ans);
  s.clear();
  t.clear();
  for(int i=0;i<v.size();++i)
    v[i].clear();
}

return 0;
}
