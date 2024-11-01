#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("print.txt","w",stdout)
#include <queue>
typedef long long ll;
using namespace std;
#define mx (int)1e6
int I,U,n;
vector<int> v;
int L[10003];
void bfs(){
	queue<int> q;
	memset(L,mx,sizeof L);
	L[I] = 0;
	q.push(I);
	bool flag = false;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u==U)
			flag = true;
		
		for(int i = 0; i<v.size(); i++){
			int nx = (v[i] + u)%10000;
			if(L[nx]>1+L[u]){
				L[nx] = 1+L[u];
				q.push(nx);
			}
		}
	}
	if(!flag)	puts("Permanently Locked");
	else printf("%d\n",L[U]);
}


int main(){
int tc = 0;
while(3==scanf("%d %d %d",&I,&U,&n)){
	if(!I && !U && !n)	break;
	for(int i = 0; i<n; i++){
		int a;	scanf("%d",&a);
		v.push_back(a);
	}
	
	printf("Case %d: ",++tc);
	bfs();
	v.clear();
}




return 0;
}

