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
};
struct eqn{
	double a,b,c;
	eqn(){};
	eqn(double x,double y,double z){
		a = x,b = y,c = z;
	}
	bool scn(){
		cin>>a>>b>>c;	return true;
	}
	bool check(){	return (!a && !b && !c);
	}
};
eqn pointsToEqn(point a,point b){
	eqn E;
	E.a = -(a.y-b.y);
	E.b = 	(a.x-b.x);
	E.c = a.x*E.a+E.b*a.y;
	return E;
}
#define EPS (double)1e-12
bool intersect(eqn one,eqn two,point &p){
	double det = one.a*two.b-one.b*two.a;
	if(fabs(det)<EPS)	return false;
//	if()
	
	p.x = (one.c*two.b-two.c*one.b)/det;
	p.y = (one.a*two.c-one.c*two.a)/det;	
return true;
}
double cnvrt(double x){
	x = (floor(x*100.0+.5))/100.0;
	return x;
}

int main(){
eqn one,two;
while(one.scn() && two.scn()){
	if(one.check() && two.check())	break;
	point p;
	bool fl = intersect(one,two,p);
	if(!fl)	puts("No fixed point exists.");
	else{
		p.x = cnvrt(p.x);
		p.y = cnvrt(p.y);
	printf("The fixed point is at %.2f %.2f.\n",p.x,p.y);
	}
} 



return 0;
}

