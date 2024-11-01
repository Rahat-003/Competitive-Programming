#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;

#define pi acos(-1)

struct point{
	double x,y;
	point(){};
	point(double a,double b){
		x = a,y = b;
	}
	void scan(){
		cin>>x>>y;
	}
	bool operator < (const point &p)	const{
	return x<p.x;
	}
};
struct eqn{
	double a,b,c;
	eqn(){};
	eqn(double x,double y,double z){
		a = x,b = y,c = z;
	}
};

double dist(point p,point q){
	return hypot(p.x-q.x,p.y-q.y);
}
eqn pointsToEqn(point p,point q){
	eqn E;
	double x1 = p.x, y1 = p.y;
	double x2 = q.x, y2 = q.y;
	E.a = -(y1-y2);
	E.b = (x1-x2);
	E.c = (E.a*x1+E.b*y1);	return E;
}
double fx(eqn E,double y){
	return (E.c-E.b*y)/E.a;
}
vector<point> v;

int main(){
int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	for(int i = 0; i<n; i++){
		point a;
		a.scan();	v.push_back(a);
	}
	sort(v.begin(),v.end());
	int sz = v.size()-1;
	double ans = dist(v[sz],v[sz-1]);
	double h = v[sz-1].y;
	
	for(int i = sz-2; i>=0; i--){
		point p = v[i];
		if(p.y>h){
			point q;
			eqn E = pointsToEqn(v[i],v[i+1]);
			q.x = fx(E,h);
			q.y = h;
			h = p.y;
			ans+=dist(p,q);
		}
	}
	ans = floor((ans*100.0+.5))/100.0;
	printf("%.2f\n",ans);
	v.clear();
}



return 0;
}

