#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
int dx[] = {1,1,1,-1,-1,-1,0,0};
int dy[] = {0,1,-1,0,1,-1,1,-1};
int tc = 0;

void dfs(int x,int y){
  v[x][y] = 2;
  for(int i=0;i<8;i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(nx>=0 && nx<v.size() && ny>=0 && ny<v.size() && v[nx][ny]==1)
      dfs(nx,ny);

  }

}

void print(){

    int cnt = 0;
    if(v.size()){
      for(int i=0;i<v.size(); i++){
        for(int j=0;j<v[i].size(); j++){
          if(v[i][j]==1){
            cnt++;
            dfs(i,j);
          }
        }
      }
      printf("Image number %d contains %d war eagles.\n",++tc,cnt);

    }


}


int main(){

int  R = 0;
string s;

while(true){
  getline(cin,s);

  if(!s.size()){
  break;
  }

  int r, gar = -1;
  string t = s;
  istringstream iss(t);

  iss>>r;
    v.assign(r,vector<int>(r,0));

  for(int i=0;i<r;i++){
    string q ;
    getline(cin,q);
    for(int j=0;j<q.size(); j++){
      if(q[j]=='1') v[i][j] = 1;
    }
  }

  print();

}



return 0;
}
