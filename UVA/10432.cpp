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

double dtor(double x){	return x*pi/180.0;
}
double round(double x){	return ((floor(x*1000.0+.5)/1000.0));
}

int main(){
double r,n;

while(cin>>r>>n){
	/*
	double x = dtor(360.0);
	double c = sqrt(2*r*r-2*r*r*cos(x/n) ) ;
	double s = (c+r+r)/2.0;
	*/
//	double area = n*(sqrt(s*(s-r)*(s-r)*(s-c)));
	double area = n*(r*r*sin(2*pi/n))/2;
	 	
	printf("%.3f\n",round(area));
}

return 0;
}

