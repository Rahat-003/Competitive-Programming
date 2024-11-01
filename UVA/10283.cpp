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
double rtod(double x){	return x*180/pi;
}


int main(){
//read;

double r,R,n,x,y,z,ans2,ans3;
while(cin>>R>>n){
	ans2 = 0,	ans3 = 0;
	if(n==1){
		printf("%.10f %.10f %.10f\n",R,ans2,ans3);
	continue;
	}
	
	r = R*sin(dtor(180/n))/(1+sin(dtor(180/n)));
	x = R-r,	y = r,	z = sqrt(x*x-y*y);
	double alpha = 90 - 180/n;
	ans2 = 2*n*(.5*z*y - pi*r*r*alpha/360);
	ans3 = pi*R*R - ans2 - n*pi*r*r;
	printf("%.10f %.10f %.10f\n",r,ans2,ans3);
}


return 0;
}

