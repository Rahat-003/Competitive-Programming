#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("print.txt","w",stdout)
typedef long long ll;
using namespace std;
int v[9][9];
struct node{
	int x,y;	
	node(){};
	node(int a,int b){
		x = a,y = b;
	}
};

void f(node p,node q,node r,int a,int b,int c){
	int z = (a-b-c)/2;
	int x = b + z;
	int y = c + z;
	v[p.x+1][p.y] = x;
	v[p.x+1][p.y+1] = y;
	v[q.x][q.y+1] = z;
	return;
}


int main(){
int t;
scanf("%d",&t);
while(t--){
	memset(v,0,sizeof v);	
	
	for(int i = 0; i<9; i+=2){
		for(int j = 0; j<=i; j+=2){
			scanf("%d",&v[i][j]);
		}
	}
	
	for(int i = 0; i<=6; i+=2){
		for(int j = 0; j<=i; j+=2){
			node p,q,r;
			p.x = i;	q.x = i+2;	r.x = i+2;
			p.y = j;	q.y = j;	r.y = j+2;
			f(p,q,r,v[i][j],v[i+2][j],v[i+2][j+2]);
		}
	}
	for(int i = 0; i<9; i++){
		for(int j = 0; j<=i; j++){
			if(i && j)	printf(" ");
			printf("%d",v[i][j]);
		}
		puts("");
	}
	
	
}


return 0;
}

