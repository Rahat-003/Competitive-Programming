#include <bits/stdc++.h>
using namespace std;

struct node{
  char c;
  int d;
  node(char a,int b){
  c = a;
  d = b;
  }

  bool operator<(const node &n1)  const{
    if(d!=n1.d) return d>n1.d;
    else  return (c - '0')<(n1.c - '0');
  }

};
vector<vector<char>> v;
  int r,c;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int x,int y, char m){
  v[x][y] = 0;
  for(int i=0;i<4;i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(nx>=0 && nx<r && ny>=0 && ny<c && v[nx][ny]==m)
      dfs(nx,ny,m);

  }


}







int main(){

int t,tc = 0;
cin>>t;
while(t--){
  cin>>r>>c;
  v.assign(r,vector<char>(c,0));

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      char w;
      cin>>w;
      v[i][j] = w;
    }
  }

  map<char,int> mp;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      char q = v[i][j];
      int e = q;
      if(e){
        dfs(i,j,q);
        mp[e]++;
      }

    }
  }
  vector<node> p;
  for(auto it = mp.begin(); it!=mp.end(); it++){
    p.push_back ( node(it->first,it->second) );
  }
  sort(p.begin(),p.end());
  mp.clear();

  printf("World #%d\n",++tc);
  for(int i=0;i<p.size(); i++){
    node x = p[i];
    printf("%c: %d\n",x.c,x.d);
  }


}

return 0;
}
