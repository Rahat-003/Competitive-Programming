#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <iostream>
#include <sstream>

#include <queue>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("print.txt","w",stdout)
typedef long long ll;
using namespace std;

struct node{
	double x,y;
	node(){};
	node(double a,double b){
		x = a,y = b;
	}
};
struct cc{
	int n;
	double d;
	cc(){};
	cc(int a,double b){
		n = a, d = b;
	}
};

double dis(double x1,double y1,double x2,double y2){
	return (sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}


	double V,T;
	int L[1005];
double sx,sy,tx,ty;
vector<vector<cc>> g;
#define mx (int)1e6
void bfs(){
	queue<int> q;
	memset(L,mx,sizeof L);
	L[0] = 0;
	q.push(0);
	bool flag = false;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		if(u==1){
			printf("Yes, visiting %d other holes.\n",L[u]-1);
			flag = true;
			break;
		}
		
		for(int i = 0; i<g[u].size(); i++){
			int p = g[u][i].n;
			double d = g[u][i].d;
			if(L[p]>1+L[u] && d<=V*T*60){
				L[p] = 1+L[u];
				q.push(p);
			}
		}
	}
	if(!flag)	puts("No.");
}

int main(){

string s;
while(getline(cin,s)){
	if(s[0]=='0' && s[2]=='0')	break;
	vector<node> v;
	istringstream iss(s);
	iss>>V>>T;
	string t;
	scanf("%lf %lf %lf %lf",&sx,&sy,&tx,&ty);
	int N = 2;
	cin.ignore();
	v.push_back(node(sx,sy));
	v.push_back(node(tx,ty));
	while(getline(cin,t)){
		istringstream ss(t);
		if(t.size()==0)	break;
		double x,y;
		ss>>x>>y;
		N++;
		v.push_back(node(x,y));
	}
	g.assign(N,vector<cc>());
	
	for(int i = 0; i<v.size(); i++){
		for(int j = i+1; j<v.size(); j++){
			node n1 = v[i],n2 = v[j];
			double distance = dis(n1.x,n1.y,n2.x,n2.y);
			g[i].push_back(cc(j,distance));
			g[j].push_back(cc(i,distance));
		}
	}
	bfs();
	
}


return 0;
}

