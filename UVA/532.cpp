#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("print.txt","w",stdout)
typedef long long ll;
using namespace std;
int L,R,C;
int sx,sy,sz,tx,ty,tz;
char g[32][32][32];
int dis[32][32][32];
#define mx (int)1e6

struct node{
	int x,y,z;
	node(int a,int b,int c){
		x = a,y = b,z = c;
	}
};
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool valid(int x,int y,int z){
	if(x<0 || y<0 || z<0 || x>=R || y>= C || z>=L)	return false;
	if(g[z][x][y]=='#')	return false;
	return true;
}

void bfs(){
	for(int k = 0; k<L; k++){
		for(int i = 0; i<R; i++){
			for(int j = 0; j<C; j++)	
				dis[k][i][j] = mx;
		}
	}
	dis[sz][sx][sy] = 0;
	queue<node> q;
	q.push(node(sx,sy,sz));
	bool fl = false;
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		
		if(x==tx && y==ty && z==tz)	fl = true;
		
		for(int i = 0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z;
			if(!valid(nx,ny,nz))	continue;
			if(dis[nz][nx][ny]>dis[z][x][y]+1){
				dis[nz][nx][ny] = 1+dis[z][x][y];
				q.push(node(nx,ny,nz));
			}
		}
		int nx = x, ny = y;
		int nz = z+1;
		if(valid(nx,ny,nz)){
			if(dis[nz][nx][ny]>dis[z][x][y]+1){
				dis[nz][nx][ny] = 1+dis[z][x][y];
				q.push(node(nx,ny,nz));
			}
		}
		nz = z-1;
		if(valid(nx,ny,nz)){
			if(dis[nz][nx][ny]>dis[z][x][y]+1){
				dis[nz][nx][ny] = 1+dis[z][x][y];
				q.push(node(nx,ny,nz));
			}
		}
	
	}
	if(!fl){
		puts("Trapped!");
	return;
	}
	printf("Escaped in %d minute(s).\n",dis[tz][tx][ty]);
	
}

int main(){
while(3==scanf("%d %d %d",&L,&R,&C)){
	if(!L && !R && !C)	break;
	
	for(int i = 0; i<L; i++){
		for(int j = 0; j<R; j++){
			for(int k = 0; k<C; k++){
				char c;
				cin>>c;
				g[i][j][k] = c;
				if(c=='S')	sx = j,sy = k,sz = i;
				if(c=='E')	tx = j,ty = k,tz = i;
			}
		}
	}	
	bfs();
}


return 0;
}

