#include <bits/stdc++.h>
using namespace std;

int r,c;
vector<vector<char>> v;


int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int dfs(int x,int y, char id){
  int cnt = 1;
  v[x][y] = 0;

  for(int i=0;i<4;i++){
    int nx = x+dx[i];
    int ny = (y+dy[i]);

    if(ny<0)  ny += c;
    if(ny==c) ny = 0;

    if(nx>=0 && nx<r && v[nx][ny]==id){
      cnt+= dfs(nx,ny,id);
    }
  }

return cnt;
}



int main(){

//  freopen("tst.txt","r",stdin);

string s;

while(true){

  getline(cin,s);
  if(!s.size()) break;

  istringstream iss(s);
  iss>>r>>c;

  v.assign(r,vector<char>(c,0));

  for(int i=0;i<r;i++){
    string t;
    getline(cin,t);
    for(int j=0;j<t.size(); j++){
     v[i][j] = t[j];
    }
  }
  int ix,iy;
  cin>>ix>>iy;

  char w = v[ix][iy];
  int present =  dfs(ix,iy,w);

  int q = 0;
  int land = 0;

  for(int i=0;i<r;i++){
    for(int j=0; j<c;j++){
      if(v[i][j]==w){
        land = dfs(i,j,w );
        q = max(land,q);
      }
    }
  }

  cout<<q<<endl;

  cin.ignore();
  cin.ignore();
}

return 0;
}
