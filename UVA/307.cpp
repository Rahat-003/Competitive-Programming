#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("print.txt","w",stdout)
typedef long long ll;
using namespace std;
#define mx (int)1e6

int R,C,sx,sy,tx,ty;
char g[30][30];
int L[30][30][4][5];

struct node{
	int x;
	int y,z,clr;
	node(){};
	node(int a,int b,int c,int d){
		x = a,y = b;
		z = c;
		clr = d;
	}
};
bool valid(int x,int y){
	if(x<0 || y<0 || x>=R || y>=C)	return false;
	if(g[x][y]=='#')	return false;
	return true;
}

void bfs(){
	bool flag = false;
	queue<node> q;
	q.push(node(sx,sy,0,0));
	memset(L,mx,sizeof L);
		L[sx][sy][0][0] = 0;
	
	while(!q.empty()){
		node u = q.front();
		int ix = u.x;
		int iy = u.y;
		int iz = u.z;
		int ic = u.clr;
		q.pop();
		
		if(ix==tx && iy==ty && ic==0){
				flag = true;
//				printf("minimum time = %d sec\n",L[tx][ty][iz][0]);
//				break;
		}
		
		if(iz==0){
			int nx,ny,nz,nc;
			nx = ix-1,ny = iy,nz = 0,nc = ic+1,nc%=5;
			if(valid(nx,ny)){
				if(L[nx][ny][nz][nc]>1+L[ix][iy][iz][ic]){
					L[nx][ny][nz][nc] = 1+L[ix][iy][iz][ic];
					q.push(node(nx,ny,nz,nc));
				}
			}
			nx = ix,ny = iy;
				if(L[nx][ny][1][ic]>1+L[ix][iy][iz][ic]){
					L[nx][ny][1][ic] = 1+L[ix][iy][iz][ic];
					q.push(node(nx,ny,1,ic));
				}
				if(L[nx][ny][3][ic]>1+L[ix][iy][iz][ic]){
					L[nx][ny][3][ic] = 1+L[ix][iy][iz][ic];
					q.push(node(nx,ny,3,ic));
				}
				if(L[nx][ny][2][ic]>2+L[ix][iy][iz][ic]){
					L[nx][ny][2][ic] = 2+L[ix][iy][iz][ic];
					q.push(node(nx,ny,2,ic));
				}
		}
		
		if(iz==1){
			int nx,ny,nz,nc;
			nx = ix,ny = iy+1,nz = 1,nc = ic+1,nc%=5;
			if(valid(nx,ny)){
				if(L[nx][ny][nz][nc]>1+L[ix][iy][iz][ic]){
					L[nx][ny][nz][nc] = 1+L[ix][iy][iz][ic];
					q.push(node(nx,ny,nz,nc));
				}
			}
			nx = ix,ny = iy;
				if(L[nx][ny][0][ic]>1+L[ix][iy][iz][ic]){
					L[nx][ny][0][ic] = 1+L[ix][iy][iz][ic];
					q.push(node(nx,ny,0,ic));
				}
				if(L[nx][ny][2][ic]>1+L[ix][iy][iz][ic]){
					L[nx][ny][2][ic] = 1+L[ix][iy][iz][ic];
					q.push(node(nx,ny,2,ic));
				}
				if(L[nx][ny][3][ic]>2+L[ix][iy][iz][ic]){
					L[nx][ny][3][ic] = 2+L[ix][iy][iz][ic];
					q.push(node(nx,ny,3,ic));
				}
		}
	
		if(iz==2){
			int nx,ny,nz,nc;
			nx = ix+1,ny = iy,nz = 2,nc = ic+1,nc%=5;
			if(valid(nx,ny)){
				if(L[nx][ny][nz][nc]>1+L[ix][iy][iz][ic]){
					L[nx][ny][nz][nc] = 1+L[ix][iy][iz][ic];
					q.push(node(nx,ny,nz,nc));
				}
			}
			nx = ix,ny = iy;
				if(L[nx][ny][1][ic]>1+L[ix][iy][iz][ic]){
					L[nx][ny][1][ic] = 1+L[ix][iy][iz][ic];
					q.push(node(nx,ny,1,ic));
				}
				if(L[nx][ny][3][ic]>1+L[ix][iy][iz][ic]){
					L[nx][ny][3][ic] = 1+L[ix][iy][iz][ic];
					q.push(node(nx,ny,3,ic));
				}
				
				if(L[nx][ny][0][ic]>2+L[ix][iy][iz][ic]){
					L[nx][ny][0][ic] = 2+L[ix][iy][iz][ic];
					q.push(node(nx,ny,0,ic));
				}
		}
	
		if(iz==3){
			int nx,ny,nz,nc;
			nx = ix,ny = iy-1,nz = iz,nc = ic+1,nc%=5;
			if(valid(nx,ny)){
				if(L[nx][ny][nz][nc]>1+L[ix][iy][iz][ic]){
					L[nx][ny][nz][nc] = 1+L[ix][iy][iz][ic];
					q.push(node(nx,ny,nz,nc));
				}
			}
			nx = ix,ny = iy;
				if(L[nx][ny][0][ic]>1+L[ix][iy][iz][ic]){
					L[nx][ny][0][ic] = 1+L[ix][iy][iz][ic];
					q.push(node(nx,ny,0,ic));
				}
				if(L[nx][ny][2][ic]>1+L[ix][iy][iz][ic]){
					L[nx][ny][2][ic] = 1+L[ix][iy][iz][ic];
					q.push(node(nx,ny,2,ic));
				}
				if(L[nx][ny][1][ic]>2+L[ix][iy][iz][ic]){
					L[nx][ny][1][ic] = 2+L[ix][iy][iz][ic];
					q.push(node(nx,ny,1,ic));
				}
		
		}
	}
	int ans = mx;
	for(int i = 0; i<4; i++)
		ans = min(ans,L[tx][ty][i][0]);
	
	
	if(!flag)	puts("destination not reachable");
	else printf("minimum time = %d sec\n",ans);
}

int main(){

	
int tc = 0;
while(2==scanf("%d %d",&R,&C)){
	if(!R && !C)	break;
	
	for(int i = 0 ;i<R; i++){
		for(int j = 0; j<C; j++){
			char x;	cin>>x;
			g[i][j] = x;
			if(x=='S'){
				sx=i,sy =j;
			}
			if(x=='T'){
				tx = i,ty = j;
			}
		}
	}
	
	if(tc)	puts("");
	printf("Case #%d\n",++tc);
	bfs();
}

return 0;
}

