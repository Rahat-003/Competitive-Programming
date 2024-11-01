#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define mx (int)1e6
typedef long long ll;
using namespace std;

vector<int> g[103][103];
bool way[103][103];
int L[103][103];
int R,C,tx,ty;
struct node{
	int x,y;
	node(){};
	node(int a,int b){
		x = a,y = b;
	}
};
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
vector<node> imp[103][103];

bool valid(int x,int y,int nx,int ny){
	if(nx<0 || ny<0 || nx>=R || ny>=C)	return false;
	for(int i = 0; i<imp[x][y].size(); i++){
		int impx = imp[x][y][i].x;
		int impy = imp[x][y][i].y;
		if(nx==impx && ny==impy)	return false;
	}
	return true;
}
void bfs(){
queue<node> q;
	memset(L,mx,sizeof L);
	
	L[0][0] = 0;
	q.push(node(0,0));
//	puts("");
	bool flag = false;
	
	while(!q.empty()){
		node u = q.front();
			int x = u.x;
			int y = u.y;
			q.pop();
//			cout<<x<<" "<<y<<" "<<L[x][y]<<endl;
			for(int i = 0; i<g[x][y].size(); i++){
				int P = g[x][y][i];
				if(P==L[x][y])	L[x][y]+=1;
//				else break;
			}
			
			
			if(x==tx && y==ty){
				printf("%d\n",L[tx][ty]);
				flag = true;
				return;
			}
			
			for(int i = 0; i<4; i++){
				int nx = dx[i] + x;
				int ny = dy[i] + y;
				if(!valid(x,y,nx,ny))	continue;
				
				if(L[nx][ny]>L[x][y]+1){
					L[nx][ny] = L[x][y]+1;
					q.push(node(nx,ny));
				}
			}
		}
		
		
}

int main(){
	freopen("tst.txt","r",stdin);
	
while(2==scanf("%d %d",&R,&C )){
	swap(R,C);
	tx = R-1,	ty = C-1; 
	int n;
	scanf("%d",&n);
	while(n--){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		swap(a,b);
		swap(c,d);
		imp[a][b].push_back(node(c,d));
	}
	int p;
	scanf("%d",&p);
	while(p--){
		int t,a,b;	scanf("%d %d %d",&t,&a,&b);
		swap(a,b);
		g[a][b].push_back(t);
	}
	bfs();
	for(int i = 0; i<103; i++){
		for(int j = 0; j<103; j++){
			imp[i][j].clear();
			g[i][j].clear();
		}
	}
	
}




return 0;
}

