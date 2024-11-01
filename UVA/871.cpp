#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> v;

int dx[] = {1,1,1,-1,-1,-1,0,0};
int dy[] = {0,1,-1,0,1,-1,1,-1};

int r,c;

int dfs(int x,int y){
  int cnt = 1;
  v[x][y] = '0';

  for(int i=0;i<8;i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
    if( nx>=0 && nx<=r && ny>=0 && ny<c && v[nx][ny]=='1' )
      cnt += dfs(nx,ny);
  }

return cnt;
}

int main(){

//freopen("tst.txt","r",stdin);

int t;
cin>>t;
cin.ignore();
cin.ignore();

while(t--){
    string s;

  r = -1;

  while(getline(cin,s)){
      if(!s.size()) break;

    v.push_back(vector<char>());

    c = s.size();
      ++r;
    for(int i=0;i<s.size(); i++){
      v[r].push_back(s[i]);
    }

  }

  int mx = 0;

  for(int i=0;i<=r;i++){
    for(int j = 0;j<v[i].size();j++){
      if(v[i][j]=='1'){
        int ans = dfs(i,j);
        mx = max(ans,mx);
      }
    }
  }

  cout<<mx<<endl;
for(int i=0;i<v.size();i++)
  v[i].clear();


if(t) cout<<endl;


}

return 0;
}
