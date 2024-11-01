#include <bits/stdc++.h>
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
#define EPS (double)1e-9
#define pi (acos(-1.0))

struct eqn{
    double a,b,c;
    eqn(){};
    eqn(double p,double q,double r){
        a = p, b = q, c = r;
    }
};

struct vec{
    double a,b;
    vec(){};
    vec(double p,double q){
        a = p,b = q;
    }
};

struct point{
	double x,y;
	point(){};
	point(double a,double b){
		x = a, y = b;
	}

	bool operator < (const point &p) const {
		if(fabs(x-p.x)>EPS)	return x<p.x;
		return y<p.y;
	}
	bool operator == (const point &p)	const {
		return (fabs(x-p.x)<EPS && fabs(y-p.y)<EPS);
	}
};

double dist(point p,point q){
    return hypot(p.x-q.x,p.y-q.y);
}

double degToRad(double angle){
    return angle*pi/180.0;
}
double radTodeg(double rad){
    return rad*180.0/pi;
}

point rotate(point p,point q,double angle){
//    counter-clockwise rotation
    angle = degToRad(angle);
    p.x-=q.x;
    p.y+=q.y;
    point r;
    r.x = p.x*cos(angle) - p.y*sin(angle) + q.x;
    r.y = p.x*sin(angle) + p.y*cos(angle) + q.y;
    return r;
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
bool areParallel(eqn p,eqn q){
    return (p.a/q.a==p.b/q.b);
}

bool isSame(eqn p,eqn q){
    return (p.a/q.a==p.b/q.b && p.b/q.b==p.c/q.c);
}
bool intersect(eqn one,eqn two, point &p){
    double det = one.a*two.b - one.b*two.a;
    if(fabs(det)<EPS)   return false;
    p.x = (one.c*two.b - one.b*two.c)/det;
    p.y = (one.a*two.c - one.c*two.a)/det;
    return true;
}

double dot(vec u,vec v){
    return u.a*v.a+u.b*v.b;
}

vec toVec(point a,point b){
    return vec(b.x-a.x,b.y-a.y);
}
double nor(vec v){
    return v.a*v.a+v.b*v.b;
}

double angle(point a,point o,point b){
    vec oa = toVec(o,a);
    vec ob = toVec(o,b);
    double m = dot(oa,ob);
    double n = sqrt(nor(oa)*nor(ob));
    return acos(m/n);
}

point translate(vec v,point a){
    return point(v.a+a.x,v.b+a.y);
}
vec scale(vec v,double d){
    return vec(v.a*d,v.b*d);
}

double disPointToLine(point p,point a,point b,point &c){
    vec ap = toVec(a,p);
    vec ab = toVec(a,b);
    double AB = nor(ab);
    double u = dot(ap,ab)/AB;
    if(u<0.0){
        c.x = a.x,  c.y = a.y;
        return dist(p,c);
    }
    if(u>1.0){
        c.x = b.x, c.y=b.y;
        return dist(p,c);
    }
    c = translate(scale(ab,u),a);
    return dist(p,c);
}
double cross(vec a,vec b){
    return (a.a*b.b - a.b*b.a);
}

double orientation(point p,point q,point r){
    double t = cross(toVec(p,q),toVec(p,r));
    return t;
    /** if t>0, r is at the left
        t==0,   collinear
        t<0, r is at the right
    */
}

double insideCircle(point p,point centre, double radius){
    double dis = dist(p,centre);
    if(dis<radius)   return -1;  ///inside
    if(dis==radius)  return 0;   ///border
    return 1;               ///outside
}

double areaOfTriangle(point p,point q,point r){
    double a = dist(p,q);
    double b = dist(q,r);
    double c = dist(p,r);
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

bool inCircle(point p1,point p2,point p3,point &centre){

    double area = areaOfTriangle(p1,p2,p3);
    double a = dist(p1,p2);
    double b = dist(p2,p3);
    double c = dist(p1,p3);
    double s = (a+b+c)/2;
    double radius = area/s;
    if(fabs(radius)<EPS)    return false;

    double ratio = dist(p1,p2)/dist(p1,p3);
    vec x = scale(toVec(p2,p3),ratio/(ratio+1));
    point p = translate(x,p2);
    eqn E = pointsToEqn(p,p1);

    ratio = dist(p1,p2)/dist(p2,p3);
    vec y = scale(toVec(p1,p3),ratio/(ratio+1));
    point q = translate(y,p1);
    eqn F = pointsToEqn(q,p2);

    bool fl = intersect(E,F,centre);
    return fl;
}

double circumCirleArea(point p,point q,point r){
    double a = dist(p,q);
    double b = dist(q,r);
    double c = dist(p,r);
    double s = (a+b+c)/2;
    double area = areaOfTriangle(p,q,r);
    return (a*b*c)/(4*area);
}
bool ccw(point a,point b,point c){
	return orientation(a,b,c)>0;
}

bool inPolygon(point pt, const vector<point> &P) {
	if ((int)P.size() == 0) return false;
	double sum = 0; // assume the first vertex is equal to the last vertex
	for (int i = 0; i < (int)P.size()-1; i++) {
		if (ccw(pt, P[i], P[i+1]))
		sum += angle(P[i], pt, P[i+1]); // left turn/ccw
		else sum -= angle(P[i], pt, P[i+1]); } // right turn/cw
return fabs(fabs(sum) - 2*pi) < EPS;
}

int main(){
/*
point p,a,b,c;
cout<<pi<<endl;
while(cin>>p.x>>p.y>>a.x>>a.y>>b.x>>b.y){
    double dis = disPointToLine(p,a,b,c);
    cout<<dis<<endl;
}
*/
/*
*/
//cout<<angle(point(0,0),point(2,0),point(2,0))<<endl;
/*
int e,t,tc = 0;
cin>>t;
while(t--){
	cin>>e;
vector<point> p;
	point a;
while(e--){
	cin>>a.x>>a.y;	p.push_back(a);
}
p.push_back(p[0]);
int q;	cin>>q;
printf("Case %d:\n",++tc);
while(q--){
cin>>a.x>>a.y;
if(inPolygon(a,p))	puts("Yes");
else puts("No");
p.clear();
}
}
*/
point wtrToA,b,a;
double deg;
while(cin>>a.x>>a.y>>b.x>>b.y>>deg){
    wtrToA = a;
    b = point(b.x-a.x,b.y-a.y);
    point c = rotate(b,point(0,0),deg);
    c = point(c.x+a.x,c.y+a.y);
    b = point(b.x+a.x,b.y+a.y);
    cout<<b.x<<" "<<b.y<<" "<<c.x<<" "<<c.y<<endl;
}




return 0;
}
