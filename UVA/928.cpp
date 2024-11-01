#include <cstdio>
#include <cmath>
#include <memory.h>
#include <vector>
#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;
#define mx (int)1e6

struct node{
	int x,y,z;
	node(){};
	node(int a,int b,int c){
		x = a,y=b,z=c;
	}
};

char g[303][303];
int L[303][303][3],R,C,sx,sy,tx,ty;
int Dx[] = {1,0,-1,0};
int Dy[] = {0,1,0,-1};
bool flag = false;

bool valid(int x,int y){
	if(x<0 || y<0 || x>=R || y>=C)	return false;
	if(g[x][y]=='#')	return false;
	return true;
}

void bfs(){
	queue<node> q;
	q.push(node(sx,sy,0));
	memset(L,mx,sizeof L);
	L[sx][sy][0] = 0;
	
	while(!q.empty()){
		node u = q.front();
		int ix = u.x;
		int iy = u.y;
		int iz = u.z;
		if(g[ix][iy]=='E'){
		flag = true;	
		break;
		}	
		q.pop();
		
		for(int i = 0; i<4; i++){
			
			bool fl = true;
			
			int nx = ix + (iz+1)*Dx[i];
			int ny = iy + (iz+1)*Dy[i];
			int nz = (iz+1);
			nz%=3;
			
			if(!valid(nx,ny))	continue;
			
				for(int j = 1; j<=iz+1; j++){
					int NX = ix + j*Dx[i];
					int NY = iy + j*Dy[i];
					
					if(!valid(NX,NY)){
						fl = false;
						break;
					}
				}	
			if(!fl)	continue;
				
				if(L[nx][ny][nz]>L[ix][iy][iz]+1){
					L[nx][ny][nz] = L[ix][iy][iz]+1;
					q.push(node(nx,ny,nz));
				}
		}
	}
	
	int ans = mx;
	for(int i = 0; i<3; i++)
		ans = min(ans,L[tx][ty][i]);
	
	if(!flag)puts("NO");
	else printf("%d\n",ans);	
}


int main(){
int t;
scanf("%d",&t);
while(t--){
	scanf("%d %d",&R,&C);
	flag = false;
	
	for(int i = 0; i<R; i++){
		for(int j = 0 ; j<C; j++){
			char  x;
			cin>>x;
			g[i][j] = x;
			
			if(x=='S'){
				sx = i;
				sy = j;
			}
			if(x=='E'){
				tx = i;
				ty = j;
			}
			
		}
	}
	
	bfs();
	
}



  return 0;
}

