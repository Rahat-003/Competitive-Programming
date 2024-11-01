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

double round(double x){		return (floor(1000.0*x+.5))/1000.0;}

int main(){
double a;

while(cin>>a){
	double x,y,z,p,q,r,m,t;
	p = a*a-pi*a*a/4.0;
	q = pi*a*a/4.0 - p;
	m = pi*a*a/6.0-sqrt(3.0)*a*a/4.0;
	t = pi*a*a/12.0-m;
	x = p-t;
	y = p-2*x;
	z = q-2*y;

	printf("%.3f %.3f %.3f\n",round(z),round(4*y),round(4*x));
}

return 0;
}

