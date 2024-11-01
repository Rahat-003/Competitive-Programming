#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <sstream>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("print.txt","w",stdout)
typedef long long ll;
using namespace std;
#define mx 10000000
struct node{
	int x,y;
	node(int a,int b){
		x = a,y = b;
	}
	/*
	bool operator < (const node &n1)	const{
	if(y!=n1.y)	return y<n1.y;
	return x<n1.x;
	}
	*/
};
vector<node> v[503];
int dis[503];
queue<int> q;
int f,n;
	
int _bfs(int a){
	int dis2[n];
	for(int i = 0; i<n; i++)
		dis2[i] = dis[i];
	queue<int> pq;
	pq.push(a)	;
	dis2[a] = 0;
	while(!pq.empty()){
		int u = pq.front();
		pq.pop();
		for(int i = 0; i<v[u].size(); i++){
			int child = v[u][i].x;
			int w = v[u][i].y;
			if(dis2[child]>dis2[u]+w){
				dis2[child] = dis2[u]+w;
				pq.push(child);
			}

		}
	}
	int ans = -1;
	for(int i = 0; i<n; i++)
		ans = max(ans,dis2[i]);
	return ans;

}	

void bfs(){
	vector<node> L;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0 ; i<v[u].size(); i++ ){
			int child = v[u][i].x;
			int w = v[u][i].y;
			if(dis[child]>w+dis[u]){
				dis[child] = w+dis[u];
				q.push(child);
			}
		}
	}
	int id,mn = mx;
	
	for(int i = 0; i<n; i++){
		int x = i, y = dis[i];
		int nd = _bfs(x);
		
		if(nd<mn){
			mn = nd;
			id = i;
		}
	}

	printf("%d\n",id+1);
}

int main(){

	
int t;
scanf("%d",&t);

while(t--){
	scanf("%d %d",&f,&n);
	for(int i = 0; i<n; i++)
		dis[i] = mx;
		
	for(int i = 0; i<f; i++){
		int F;	scanf("%d",&F);
		F-=1;
		q.push(F);
		dis[F] = 0;
	}
	string s;
	cin.ignore();
	int cnt = 0;
	while(getline(cin,s)){
		if(!s.size())	break;
		cnt++;
		istringstream iss(s);
		int a,b,c;
		iss>>a>>b>>c;
		a-=1, b-=1;
		v[a].push_back(node(b,c));
		v[b].push_back(node(a,c));
	}
	bfs();

	if(t)	puts("");
	for(int i = 0; i<=n; i++)
		v[i].clear();
}

return 0;
}

