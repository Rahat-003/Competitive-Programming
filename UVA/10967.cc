#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <iostream>
#include <queue>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("print.txt","w",stdout)
typedef long long ll;
using namespace std;
int sx,sy,tx,ty;
int r,c;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

char g[102][102];
int dd[102][102];
int dis[102][102];
#define mx (int)1e6
struct node{
    int x,y;
    node(){};
    node(int a,int b){
        x = a,y = b;
    }
};
bool valid(int x,int y,int nx,int ny){
	if(g[x][y]=='#')	return false;
	if(nx<0 || ny<0 || nx>=r || ny>=c)	return false;
	if(g[nx][ny]=='#')	return false;
	return true;
}

bool valid3(int x,int y,int nx,int ny){
    if(g[nx][ny]=='W' && x==nx && ny==y+1)  return true;
    if(g[nx][ny]=='E' && x==nx && ny==y-1)  return true;
    if(g[nx][ny]=='N' && y==ny && x==nx-1)  return true;
    if(g[nx][ny]=='S' && y==ny && x==nx+1)  return true;
return false;
}

queue<node> q;
void check(int x,int y,int nx,int ny){
	if(g[x][y]=='.' && g[nx][ny]=='.' && dis[nx][ny]>1+dis[x][y]){
		dis[nx][ny] = 1+dis[x][y];
		q.push(node(nx,ny));
	}
	if(g[x][y]=='.' && g[nx][ny]!='.' && valid3(x,y,nx,ny) && dis[nx][ny]>dis[x][y]+1){
		dis[nx][ny] = 1+dis[x][y];
		q.push(node(nx,ny));
	}
	if(g[x][y]!='.' ){
		int L = 1+dis[x][y];
		int M = dd[x][y];
		if(x-1==nx && y==ny && g[x][y]=='W' && (g[nx][ny]=='S' || g[nx][ny]=='.') && dis[nx][ny]>L+M ){
			dis[nx][ny] = L+M;	q.push(node(nx,ny));
		}
		if(x+1==nx && y==ny && g[x][y]=='W' && (g[nx][ny]=='N' || g[nx][ny]=='.') && dis[nx][ny]>L+M ){
			dis[nx][ny] = L+M;	q.push(node(nx,ny));
		}
		if(x==nx && ny==y+1 && g[x][y]=='W' && (g[nx][ny]=='W' || g[nx][ny]=='.') && dis[nx][ny]>L+2*M ){
			dis[nx][ny] = L+2*M;	q.push(node(nx,ny));
		}
		
		if(x-1==nx && y==ny && g[x][y]=='E' && (g[nx][ny]=='S' || g[nx][ny]=='.') && dis[nx][ny]>L+M ){
			dis[nx][ny] = L+M;	q.push(node(nx,ny));
		}
		if(x+1==nx && y==ny && g[x][y]=='E' && (g[nx][ny]=='N' || g[nx][ny]=='.') && dis[nx][ny]>L+M ){
			dis[nx][ny] = L+M;	q.push(node(nx,ny));
		}
		if(x==nx && ny==y-1 && g[x][y]=='E' && (g[nx][ny]=='E' || g[nx][ny]=='.') && dis[nx][ny]>L+2*M ){
			dis[nx][ny] = L+2*M;	q.push(node(nx,ny));
		}
		
		if(ny==y-1 && x==nx && g[x][y]=='N' && (g[nx][ny]=='E' || g[nx][ny]=='.') && dis[nx][ny]>L+M ){
			dis[nx][ny] = L+M;	q.push(node(nx,ny));
		}
		if(ny==y+1 && x==nx && g[x][y]=='N' && (g[nx][ny]=='W' || g[nx][ny]=='.') && dis[nx][ny]>L+M ){
			dis[nx][ny] = L+M;	q.push(node(nx,ny));
		}
		if(y==ny && nx==x+1 &&g[x][y]=='N' && (g[nx][ny]=='N' || g[nx][ny]=='.') && dis[nx][ny]>L+2*M ){
			dis[nx][ny] = L+2*M;	q.push(node(nx,ny));
		}
		
		if(ny==y-1 && x==nx && g[x][y]=='S' && (g[nx][ny]=='E' || g[nx][ny]=='.') && dis[nx][ny]>L+M ){
			dis[nx][ny] = L+M;	q.push(node(nx,ny));
		}
		if(ny==y+1 && x==nx && g[x][y]=='S' && (g[nx][ny]=='W' || g[nx][ny]=='.') && dis[nx][ny]>L+M ){
			dis[nx][ny] = L+M;	q.push(node(nx,ny));
		}
		if(y==ny && nx==x-1 && g[x][y]=='S' && (g[nx][ny]=='S' || g[nx][ny]=='.') && dis[nx][ny]>L+2*M ){
			dis[nx][ny] = L+2*M;	q.push(node(nx,ny));
		}
		
	}
	
}

void bfs(){
	for(int i = 0; i<r; i++){
		for(int j = 0; j<c; j++)	dis[i][j] = mx;
	}
	dis[sx][sy] = 0;
	q.push(node(sx,sy));
	bool fl = false;
	while(!q.empty()){
		node u = q.front();
		int x = u.x;
		int y = u.y;
		if(x==tx && y==ty){
		fl = true;
		}	
		q.pop();
		
		for(int i = 0; i<4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(valid(x,y,nx,ny)==false)	continue;
			check(x,y,nx,ny);
			
		}
	}
	
	if(!fl)	puts("Poor Kianoosh");
	else printf("%d\n",dis[tx][ty]);
	
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
        }
    }
    for(int i = 0; i<r; i++)
        for(int j = 0; j<c; j++){
            char c = g[i][j];
            if(c=='N' || c=='S' || c=='E' || c=='W'){
                scanf("%d",&dd[i][j]);
            }
        }
	    bfs();
}

return 0;
}

