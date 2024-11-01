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

#define EPS 1e-14
struct point{
	double x,y;
	point(){};
	point(double a,double b){
		x = a,y = b;
	}
};
double round(double x){		return (floor(100000.0*x+.5))/100000.0;}
double dist(point a,point b){	return hypot(a.x-b.x,a.y-b.y);	}

bool inside(point c,double r,point p){
	double x = dist(c,p);
	if(fabs(r-x)<EPS)	return true;
	if(r>x)	return true;
	return false;
}

int main(){
	

double a;
int n;

while(cin>>n>>a){
	if(!n && !a)		break;
	double cnt = 0,x = (double)n;
		point A(0,0),B(0,a),C(a,a),D(0,a);	
		
	for(int i = 0; i<n; i++){
		point p;	cin>>p.x>>p.y;
		if(inside(point(0,0),a,p) && inside(point(a,0),a,p) && inside(point(a,a),a,p) && inside(point(0,a),a,p) )
		cnt++;
	}
	
	printf("%.5f\n",round(cnt*a*a/x));
}

return 0;
}

