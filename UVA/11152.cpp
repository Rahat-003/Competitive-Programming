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
/*
double round(double x){
	x = (floor(x*10000.0+.5))/10000.0;
	return x;
}
*/
double s;
double areaOfTriangle(double a,double b,double c){
	 s = (a+b+c)/2.0;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}
#define pi acos(-1.0)

int main(){
double a,b,c;
while(cin>>a>>b>>c){
	double t = areaOfTriangle(a,b,c);
	double r_cir = (a*b*c)/(4*t);
	double r_in = t/s;
	double sun = pi*r_cir*r_cir-t,		rose = pi*r_in*r_in,		violet = t-rose;
	
	printf("%.4f %.4f %.4f\n",sun,violet,rose);
}

return 0;
}

