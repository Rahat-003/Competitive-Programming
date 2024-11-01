#include <bits/stdc++.h>
using namespace std;

int r,c;

struct node{
  char c;
  int d;

  node(char x,int y){
  c = x;
  d = y;
  }

  bool operator<(const node& n1)  const{
    if(d!=n1.d) return d>n1.d;
    else return (c- 'A')<(n1.c - 'A');
  }

};

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
vector<vector<char>> v;

int dfs(int x,int y,char z){
  int cnt = 1;
  v[x][y] = '.';
  for(int i=0;i<4;i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(nx>=0 && nx<r && ny>=0 && ny<c && v[nx][ny]==z){
      cnt+=dfs(nx,ny,z);
    }
  }
  return cnt;

}



int main(){
int tc = 0;
while(cin>>r>>c){
  if(!r && !c)  break;
  v.assign(r,vector<char>(c,'.'));

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      char x;
      cin>>x;
      v[i][j] = x;
    }
  }
  vector<node> w;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      char x = v[i][j];
    if(x!='.'){
      int tot = dfs(i,j,x);
      w.push_back(node(x,tot));
    }
    }
  }
  sort(w.begin(),w.end());
  printf("Problem %d:\n",++tc);
  for(int i=0;i<w.size();i++){
    printf("%c %d\n",w[i].c,w[i].d);
  }

}
return 0;
}
