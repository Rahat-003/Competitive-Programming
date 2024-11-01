
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vis,vis2;

int R,C,cnt = 1;
int dx[] = {1,1,1,-1,-1,-1,0,0};
int dy[] = {0,1,-1,0,1,-1,1,-1};

void dfs(int x,int y){
  vis[x][y]=2;

  for(int i=0;i<8;i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(nx>=0 && nx<R && ny>=0 && ny<C && vis[nx][ny]==1 ){
      cnt++;
      dfs(nx,ny);
    }
  }
}

int main(){


int t;
cin>>t;

string s;
bool fl = false;
cin.ignore();
cin.ignore();
while(t--){
    if(fl)  cout<<endl;
     R = 0; cnt = 1;
    vis.assign(103,vector<int>(103,0));
    vis2.assign(103,vector<int>(103,0));
fl = true;


while(getline(cin,s)){
    if(!s.size()){
     break;
    }

    string t = s;
    istringstream iss(t);
    int x = -1,y = -1;
    iss>>x>>y;

    if(x!=-1 && y!=-1){
        x-=1; y-=1;

      if(!vis[x][y])  cout<<0<<endl;
      else  {

      dfs(x,y);
      cout<<cnt<<endl;
     cnt = 1;
      }
     vis = vis2;
    continue;
    }

    C = s.size();
    for(int i=0;i<s.size(); i++)
      if(s[i]=='W'){
        vis[R][i] = 1;
        vis2[R][i] = 1;
      }
R++;

}
}

return 0;
}
