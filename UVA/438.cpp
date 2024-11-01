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
double round(double x){
	x = (floor(x*100.0+.5))/100.0;
	return x;
}

eqn perp(eqn A,point p,point q){
	point m( (p.x+q.x)/2.0, (p.y+q.y)/2.0 );
	eqn E;
	E.a = A.b;	E.b = -A.a;
	E.c = E.a*m.x + E.b*m.y;
	return E;
}

int main(){

point p,q,r;

while(cin>>p.x>>p.y>>q.x>>q.y>>r.x>>r.y){
	eqn pq = pointsToEqn(p,q);
	eqn pr = pointsToEqn(p,r);
	
	pq = perp(pq,p,q);
	pr = perp(pr,p,r);
	point R = intersect(pq,pr);
	double rad = dist(R,p);
	printf("%.2f\n",round(2*pi*rad));

}

return 0;
}

