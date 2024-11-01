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

struct point{
	double x,y;
	point(){};
	point(double a,double b){
		x = a,y = b;
	}
	void CIN(){
		cin>>x>>y;	return;
	}
};
struct eqn{
	double a,b,c;
	eqn(){
	};
	eqn(double x,double y,double z){
		a = x,b = y,c = z;
	}
};
#define EPS 1e-12

double dist(point a,point b){
	return hypot(a.x-b.x,a.y-b.y);
}

eqn pointsToEqn(point a,point b){
    eqn E;
    /// ax + by = c
    E.a = -(a.y - b.y);
    E.b =  (a.x - b.x);
    E.c =  (E.a*a.x + E.b*a.y);

    if(fabs(E.a)<EPS) E.a = 0;
    if(fabs(E.b)<EPS) E.b = 0;
    if(fabs(E.c)<EPS) E.c = 0;
    return E;
}

point intersect(eqn one,eqn two){
	point p;
    double det = one.a*two.b - one.b*two.a;
//    if(fabs(det)<EPS)   return false;
    p.x = (one.c*two.b - one.b*two.c)/det;
    p.y = (one.a*two.c - one.c*two.a)/det;
    return p;
//    return true;
}

point internal(point b,point c){
	point p;
	p.x = b.x+(c.x-b.x)/3.0;
	p.y = b.y+(c.y-b.y)/3.0;
	return p;
}

double areaOfTriangle(point p,point q,point r){
    double a = dist(p,q);
    double b = dist(q,r);
    double c = dist(p,r);
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}


int main(){
	
	
int t;
cin>>t;
while(t--){
	point a,b,c,d,e,f,p,q,r;
	
	a.CIN();	b.CIN();	c.CIN();
	
	f = internal(a,b);
	d = internal(b,c);
	e = internal(c,a);

	p = intersect(pointsToEqn(a,d),pointsToEqn(b,e));
	q = intersect(pointsToEqn(c,f),pointsToEqn(b,e));
	r = intersect(pointsToEqn(a,d),pointsToEqn(c,f));
	
	
	double area = areaOfTriangle(p,q,r) ;	
	area = floor(area+.5);
	ll ans = (ll)area;
	
	printf("%lld\n",ans);
}

return 0;
}

