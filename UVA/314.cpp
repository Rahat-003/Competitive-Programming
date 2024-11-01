#include <cstdio>
#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
int R,C;
int sx,sy,tx,ty,L[55][55][4],g[55][55];
string s;

bool valid(int x,int y){
	if(x<=0 || y<=0 || x>=R || y>=C)	return false;
	return g[x][y]==0;
}

int num(string s){
	if(s=="north")	return 0;
	if(s=="east")	return 1;
	if(s=="south")	return 2;
	if(s=="west")	return 3;	
}
struct node{
	int x,y,dir;
	node(){};
	node(int p,int q,int r){
		x = p,y = q,dir= r;
	}
};
#define mx (int)1e6
void bal(int x,int y,int s,int &nx,int &ny,int m){
	nx = x,ny = y;
	if(s==0)	nx-=m;
	if(s==2)	nx+=m;
	if(s==1)	ny+=m;
	if(s==3)	ny-=m;
}
queue<node> q;

void check(int x,int y,int z,int inc,int cur){
	if(!valid[x][y])	return;
	if(L[x][y][z]> (cur+inc) ){
		L[x][y][z] = cur+inc;
		q.push(node(x,y,z));
	}
	return;
}

void bfs(){
	int D = num(s);
	q.push(node(sx,sy,D));
	memset(L,mx,sizeof L);
	
	L[sx][sy][D] = 0;
	bool flag = false;
	
	while(!q.empty()){
		node u = q.front();
		int x = u.x;
		int y = u.y;
		int z = u.dir;
		q.pop();
		int cur = L[x][y][z];
		if(x==tx && y==ty){
			flag = true;
		}
		
		if(z==0){
			check(x,y,1,1,cur);
			check(x,y,3,1,cur);
			check(x,y,2,2,cur);
		}
		if(z==1){
			check(x,y,0,1,cur);
			check(x,y,2,1,cur);
			check(x,y,3,2,cur);
		}
		if(z==2){
			check(x,y,1,1,cur);
			check(x,y,3,1,cur);
			check(x,y,0,2,cur);
		}
		if(z==3){
			check(x,y,2,1,cur);
			check(x,y,0,1,cur);
			check(x,y,1,2,cur);
		}
		
		for(int i = 1; i<=3; i++){
			int nx,ny;
			bal(x,y,z,nx,ny,i);
			if(!valid(nx,ny))	break;
			check(nx,ny,z,1,cur);
		}
	}
	
	int ans = mx;
	for(int i = 0; i<4; i++)	
		ans = min(ans,L[tx][ty][i]);
	
	if(!flag)	puts("-1");
	else printf("%d\n",ans);	
}

void f(int x,int y){
	g[x][y] = 1;
	g[x+1][y] = 2;
	g[x][y+1] = 2;
	g[x+1][y+1] = 2;
}

int main(){

while(2==scanf("%d %d",&R,&C)){
	if(!R && !C)	break;
	memset(g,0,sizeof g);
	for(int i = 0; i<R; i++){
		for(int j = 0; j<C; j++){
		int n;	
		
		scanf("%d",&n);
		if(n==1){
			g[i][j] = n;
			f(i,j);
			}
		}
	}
	scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
	cin>>s;
	bfs();
}
return 0;
}


