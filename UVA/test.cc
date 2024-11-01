#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <queue>
#include <iostream>
#include <algorithm>
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("print.txt","w",stdout)
typedef long long ll;
using namespace std;
int sx,sy,tx,ty;
    int r,c;

struct door{
    char c;
    int x,y;
    door(char p,int q,int r){
        c = p, x = q, y = r;
    }
};
char g[102][102];
int dd[102][102];
vector<door> D;
int dis[102][102];
#define mx (int)3e4
struct node{
    int x,y;
    node(){};
    node(int a,int b){
        x = a,y = b;
    }
};

bool valid(int x,int y){
    if(x<0 || y<0 || x>=r || y>=c)  return false;
    if(g[x][y]=='.')    return true;
    return false;
}
bool valid2(int x,int y){
    if(g[x][y]=='.')    return true;
    return false;
}
bool valid3(int x,int y,int nx,int ny){
    if(g[nx][ny]=='W' && x==nx && ny==y+1)  return true;
    if(g[nx][ny]=='E' && x==nx && ny==y-1)  return true;
    if(g[nx][ny]=='N' && y==ny && x==nx-1)  return true;
    if(g[nx][ny]=='S' && y==ny && x==nx+1)  return true;
return false;
}
    queue<node> q;

void F(int x,int y){
    int nx,ny,L;
    if(g[x][y]=='W'){
    nx = x-1, ny = y;
    if(valid(nx,ny)){ L = dd[x][y]; if(dis[nx][ny]>L){dis[nx][ny] = L; q.push(node(nx,ny)); }}
    nx = x+1, ny = y;
    if(valid(nx,ny)){ L = dd[x][y]; if(dis[nx][ny]>L){dis[nx][ny] = L; q.push(node(nx,ny)); }}
    nx = x; ny = y+1;
    if(valid(nx,ny)){ L = 2*dd[x][y]; if(dis[nx][ny]>L){dis[nx][ny] = L; q.push(node(nx,ny)); }}
    }

    if(g[x][y]=='E'){
    nx = x-1, ny = y;
    if(valid(nx,ny)){ L = dd[x][y]; if(dis[nx][ny]>L){dis[nx][ny] = L; q.push(node(nx,ny)); }}
    nx = x+1, ny = y;
    if(valid(nx,ny)){ L = dd[x][y]; if(dis[nx][ny]>L){dis[nx][ny] = L; q.push(node(nx,ny)); }}
    nx = x; ny = y-1;
    if(valid(nx,ny)){ L = 2*dd[x][y]; if(dis[nx][ny]>L){dis[nx][ny] = L; q.push(node(nx,ny)); }}
    }

    if(g[x][y]=='N'){
    nx = x, ny = y+1;
    if(valid(nx,ny)){ L = dd[x][y]; if(dis[nx][ny]>L){dis[nx][ny] = L; q.push(node(nx,ny)); }}
    nx = x, ny = y-1;
    if(valid(nx,ny)){ L = dd[x][y]; if(dis[nx][ny]>L){dis[nx][ny] = L; q.push(node(nx,ny)); }}
    nx = x-1; ny = y;
    if(valid(nx,ny)){ L = 2*dd[x][y]; if(dis[nx][ny]>L){dis[nx][ny] = L; q.push(node(nx,ny)); }}
    }

    if(g[x][y]=='S'){
    nx = x, ny = y+1;
    if(valid(nx,ny)){ L = dd[x][y]; if(dis[nx][ny]>L){dis[nx][ny] = L; q.push(node(nx,ny)); }}
    nx = x, ny = y-1;
    if(valid(nx,ny)){ L = dd[x][y]; if(dis[nx][ny]>L){dis[nx][ny] = L; q.push(node(nx,ny)); }}
    nx = x+1; ny = y;
    if(valid(nx,ny)){ L = 2*dd[x][y]; if(dis[nx][ny]>L){dis[nx][ny] = L; q.push(node(nx,ny)); }}
    }

}

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int bfs(){
    memset(dis,mx,sizeof dis);
    dis[sx][sy] = 0;
    q.push(node(sx,sy));
    while(!q.empty()){
        node u = q.front();
        int x = u.x;
        int y = u.y;
        q.pop();
        for(int i = 0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(!valid(nx,ny))   continue;
            if(valid2(nx,ny)){
                if(dis[nx][ny]>1+dis[x][y]){
                    dis[nx][ny] = 1+dis[x][y];
                    q.push(node(nx,ny));
                }
            }
            else if(valid3(x,y,nx,ny)){
                int NX,NY;
                F(nx,ny);
            }
        }
    }
}


int main(){
int t;
scanf("%d",&t);

while(t--){
    scanf("%d %d",&r,&c);
    sx = r-1, sy = 0, tx = 0, ty = c-1;
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            char c;
            cin>>c;
            g[i][j] = c;
//                D.push_back(door(c,i,j));
        }
    }
    for(int i = 0; i<r; i++)
        for(int j = 0; j<c; j++){
            char c = g[i][j];
            if(c=='N' || c=='S' || c=='E' || c=='W'){
                scanf("%d",&dd[i][j]);
            }
        }
    int ans = bfs();
cout<<ans<<endl;
}

return 0;
}

