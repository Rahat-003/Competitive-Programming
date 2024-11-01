#include <queue>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
#define mx (ll)1e7

ll s,d,n,e,cost;
struct node{
	ll b,c;
	node(){};
	node(ll p,ll q){
		b = p,c = q;
	}

};
vector<node> graph[10002],rgraph[10002];
void dj(){
	ll dis1[n+1],dis2[n+1];

	for(ll i = 0; i<n; i++){
		dis1[i] = mx;
		dis2[i] = mx;
	}
	
	queue<ll> q;
	q.push(s);
	dis1[s] = 0;
	bool fl = false;
	while(!q.empty()){
		ll x = q.front();
		q.pop();
		if(x==d)	fl = true;
		for(ll i = 0; i<graph[x].size(); i++){
			ll child = graph[x][i].b;
			ll w = graph[x][i].c;
			if(dis1[child]>dis1[x]+w){
				dis1[child] = dis1[x]+w;
				q.push(child);
			}
		}
	}
	if(!fl){
		puts("-1");
		return;
	}
	
	q.push(d);
	dis2[d] = 0;
	while(!q.empty()){
		ll u = q.front();
		q.pop();
		for(ll i = 0; i<rgraph[u].size(); i++){
			ll child = rgraph[u][i].b;
			ll w = rgraph[u][i].c;
			if(dis2[child]>w+dis2[u]){
				dis2[child] = w+dis2[u];
				q.push(child);
			}
		}
	}
	ll ans = -1;
	for(ll i = 0; i<n; i++){
		for(ll j = 0; j<graph[i].size(); j++){
			ll x = i;
			ll y = graph[i][j].b;
			ll z = graph[i][j].c;
			ll T = dis1[x]+dis2[y]+z;
			if( T <= cost )	ans = max(ans,z);
		}
	}
	cout<<ans<<endl;
}


int main(){
//	freopen("tst.txt","r",stdin);
	
ll t;
scanf("%lld",&t);
while(t--){
	scanf("%lld %lld %lld %lld %lld",&n,&e,&s,&d,&cost);
	s-=1,d-=1;

	while(e--){
		ll a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		a-=1,b-=1;
		graph[a].push_back(node(b,c));
		rgraph[b].push_back(node(a,c));
	}
	dj();
	for(ll i = 0; i<n; i++){
		graph[i].clear();
		rgraph[i].clear();
	}
}




return 0;
}

