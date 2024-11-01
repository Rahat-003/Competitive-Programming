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

double round(double x){
	x = (floor(x*1000.0+.5))/1000.0;
	return x;
}

double radToDeg(double x){
	return x*180.0/pi;
}
double degToRad(double x){
	return x*pi/180.0;
}

int main(){
double l,w,h,theta,a,b,c;

while(cin>>l>>w>>h>>theta){
		a = l;
		b = l/tan(degToRad(90-theta));
		double area = .5*a*b;
		double rem = l*w*h-area*w;
		
		if(b>h){
			rem = w*.5*h*h/tan(degToRad(theta));
		}
		double ans = round(rem);

		printf("%.3f mL\n",ans);
}

return 0;
}

