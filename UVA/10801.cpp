#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("print.txt","w",stdout)
typedef long long ll;
using namespace std;

vector<int> tym;

#define mx 3000000
vector<int> g[5];
vector<int> G[105];
struct node{
	int x,lift;
	node(){};
	node(int a,int b){
		x = a, lift = b;
	}
};

int dis[5][105];

void f(int l,int n,int cost){
	for(int i = 0; i<g[l].size(); i++){
		int child = g[l][i];
		if(child==n)    continue;
		int w = cost + abs(n-child)*tym[l];
		if(dis[l][child]>w)	dis[l][child] = w;
	}
}

int dj(int s,int d){
    for(int i = 0; i<5; i++){
        for(int j = 0; j<105; j++) dis[i][j] = mx;
    }

    dis[s][0] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i<g[u].size(); i++){
            int child = g[u][i];
            if(dis[u][child]==mx){
                dis[u][child] = tym[u]*child;
            }
            for(int j = 0; j<G[child].size(); j++){
                int nl = G[child][j];
                if(nl!=u && dis[nl][child] >  (60+dis[u][child])){
                    dis[nl][child] = 60+dis[u][child];
                    f(nl,child,dis[nl][child]);
                    q.push(nl);
                }
            }
        }
    }
    int ans = mx;
    for(int i = 0; i<tym.size(); i++)
        ans = min(ans,dis[i][d]);
return ans;
}



int main(){
int n,d;
while(2==scanf("%d %d",&n,&d)){
	for(int i = 0; i<n; i++){
		int x;	scanf("%d",&x);
		tym.push_back(x);
	}
	cin.ignore();
	vector<int> zero;

	for(int i = 0; i<n; i++){
		string s;
		getline(cin,s);
		int b;
		istringstream iss(s);
		while(iss>>b){
			if(!b)	zero.push_back(i);
			g[i].push_back(b);
			G[b].push_back(i);
		}
	}

	int ans = mx;
    for(auto i:zero){
		int x = dj(i,d);
		ans = min(ans,x);
	}
	if(ans==mx) puts("IMPOSSIBLE");
	else printf("%d\n",ans);
	tym.clear();
	for(int i = 0; i<5; i++)    g[i].clear();
	for(int i = 0; i<105; i++)  G[i].clear();
}


return 0;
}


