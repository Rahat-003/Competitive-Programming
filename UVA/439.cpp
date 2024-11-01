#include <cstdio>
#include <cmath>
#include <vector>
#include <sstream>
#include <queue>
#include <memory.h>
#include <iostream>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("print.txt","w",stdout)
typedef long long ll;
using namespace std;

int dx[] = {2,2,-1,-1,1,1,-2,-2};
int dy[] = {1,-1,2,-2,2,-2,1,-1};
int sx,sy,tx,ty;

bool valid(int x,int y){
	if(x<0 || y<0 || x>=8 || y>=8)	return false;
	return true;
}
struct node{
	int x,y;
	node(int a,int b){
		x = a,y = b;
	}
};

int ar[9][9];
int L[9][9];
string s = "abcdefgh";

void bfs(){
	for(int i = 0; i<9; i++){
		for(int j = 0; j<9; j++)
			L[i][j] = 100000;
	}
	
	L[sx][sy] = 0;
	queue<node> q;
	q.push(node(sx,sy));
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		
		if(x==tx && y==ty){
			printf("%d knight moves.\n",L[tx][ty]);
			return;
		}
		
		for(int i = 0; i<8; i++){
			int nx = x + dx[i];
			int ny = y+dy[i];
		
		if(!valid(nx,ny))	continue;
		if(L[nx][ny]>1+L[x][y]){
			L[nx][ny] = 1+L[x][y];
			q.push(node(nx,ny));
		}
		
		}
	}


}
int main(){
string t;
while(getline(cin,t)){
	
istringstream iss(t);

char a,b;
iss>>a>>sy>>b>>ty;
sx = s.find(a);
tx = s.find(b);
sy--;
ty--;
cout<<"To get from "<<a<<sy+1<<" to "<<b<<ty+1<<" takes ";
	bfs();

}

	
return 0;
}

