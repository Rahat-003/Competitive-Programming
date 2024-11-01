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

#define pi acos(-1.0)

double areaOfCircle(double r){
	return pi*r*r;
}
double radToDeg(double x){
	return x*180.0/pi;
}
double degToRad(double x){
	return x*pi/180.0;
}

double ang(double a,double b,double c){
	double x = acos((a*a+b*b-c*c)/(2*a*b));
	return radToDeg(x);
}

int main(){
	
int t;
cin>>t;
while(t--){

	double r1,r2,r3;
	
	cin>>r1>>r2>>r3;
	
	double c1 = areaOfCircle(r1);
	double c2 = areaOfCircle(r2);
	double c3 = areaOfCircle(r3);
	double a,b,c,tri,s;
	
	c = r1+r2,	a = r2+r3,	b = r1+r3;
	s = (a+b+c)/2;	tri = sqrt(s*(s-a)*(s-b)*(s-c));
	
	double C3 = ang(a,b,c),	C1 = ang(b,c,a),	C2 = ang(a,c,b);
	double ans = tri - (c1*C1+c2*C2+c3*C3)/360;
	
	printf("%.6f\n",ans);

}

return 0;
}

