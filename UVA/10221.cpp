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
#define EPS 1e-12



double rtod(double x){	return x*180.0/pi;}
double dtor(double x){	return x*pi/180.0;}

double ang(double a,double b,double c){
	return rtod(acos( (a*a+b*b-c*c)/(2*a*b) ));
}

double round(double x){
	return ((floor(x*1000000.0+.5))/1000000.0);
}

int main(){
double a,b;	string s;

while(cin>>a>>b>>s){
	a+=6440;
	if(s=="min")	b/=60.0;
	if(b>180)	b = 360-b;
	
	double circum = 2*pi*a;
	double arc,len;
	arc = b*circum/360.0;
	len = sqrt(2*a*a-2*a*a*cos(dtor(b)));
	printf("%.6f %.6f\n",arc,len);
}

return 0;
}

