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
double a,b,c;
double inCircle(){
	double s = (a+b+c)/2;
	double T = s*(s-a)*(s-b)*(s-c);
	if(T<=0)	return 0;
    double area = sqrt(T);
    double radius = area/s;
    return radius;
}
double round(double x){
	x = (floor(x*1000.0+.5))/1000.0;
	return x;
}


int main(){

while(cin>>a>>b>>c){
	double r = inCircle();
	printf("The radius of the round table is: %.3f\n",round(r));	
}

return 0;
}

