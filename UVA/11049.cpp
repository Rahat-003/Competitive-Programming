#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("print.txt","w",stdout)
typedef long long ll;
using namespace std;
int sx,sy,tx,ty;
int g[15][15];
int L[15][15];
int m(int a){
	return 2*a-1;
}
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
string D = "SEWN";

struct node{
	int x,y;
	char c;
	node(){};
	node(int a,int b,char z = ' '){
		x = a, y = b;
		c = z;
	}
};
bool valid(int x,int y){
	if(x<0 || y<0 || x>12 || y>12)	return false;
	if(g[x][y]==0)	return false;
return true;
}
bool check(int x,int y){
	if(x<=0 || y<=0 || x>=12 || y>=12)	return false;
	return true;
}

void bfs(){
	for(int i = 0; i<15; i++){
		for(int j = 0; j<15; j++)
			L[i][j] = 100000;
	}
	queue<node> q;
	q.push(node(sx,sy));
	L[sx][sy] = 0;
	node par[15][15];
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for(int i = 0; i<4; i++){
			int _x = x + dx[i];
			int _y = y + dy[i];
			int nx = x + 2*dx[i];
			int ny = y + 2*dy[i];
		if(!valid(_x,_y))	continue;
		if(!check(nx,ny))	continue;
		if(L[nx][ny]>1+L[x][y]){
		node P;
			P.x = x;
			P.y = y;
			P.c = D[i];
			par[nx][ny] = P;
			L[nx][ny] = 1+L[x][y];
			q.push(node(nx,ny));
		}
		}
	}
	node TT;
	TT.x = tx, TT.y = ty;
	string ans;
	while(true){
		if(TT.x==sx && TT.y==sy)	break;
	if( !(TT.x==tx && TT.y==ty) )	ans.push_back(TT.c);
		int x = TT.x, y = TT.y;
		TT = par[x][y];
	}
	ans.push_back(TT.c);
	reverse(ans.begin(),ans.end());
	cout<<ans<<'\n';

}

int main(){
while(2==scanf("%d %d",&sy,&sx)){
	if(!sx && !sy)	break;	
	scanf("%d %d",&ty,&tx);
	sx = m(sx), sy = m(sy), tx = m(tx), ty = m(ty);
	int a,b,c,d;
	for(int i = 0; i<15; i++){
		for(int j = 0; j<15; j++)
			g[i][j] = 1;
	}
	
	for(int i = 0; i<3; i++){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if(a==c){
			for(int j = 2*b; j<=2*d; j++)
				g[j][2*a] = 0;
		}
		if(b==d){
			for(int j = 2*a; j<=2*c; j++)
				g[2*b][j] = 0;
		}
	}
	bfs();

}

return 0;
}

