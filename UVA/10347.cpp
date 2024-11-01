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

double round(double x){
	x = (floor(x*1000.0+.5))/1000.0;
	return x;
}

double len(double ma,double mb,double mc){
	double c = 4*(2*ma*ma+2*mb*mb-mc*mc)/9.0;
	return c;
}
#define EPS 1e-12
int main(){


double x,y,z;
while(cin>>x>>y>>z){
	vector<double> v;
	double a,b,c,s;
	a = len(y,z,x);
	b = len(x,z,y);
	c = len(x,y,z);
	if(a<=0 || b<=0 || c<=0){
		puts("-1.000");	continue;
	}
	a = sqrt(a);
	b = sqrt(b);
	c = sqrt(c);
	v.push_back(a);	v.push_back(b);	v.push_back(c);
	sort(v.begin(),v.end());
	
	if( (v[0]+v[1])<=v[2] /* || a<=0 || b<=0 || c<=0 */ ){
		puts("-1.000");	continue;
	}
	
	s = (a+b+c)/2.0;
	double T = s*(s-a)*(s-b)*(s-c);
	double area = sqrt(T);
	area = round(area);
	if(fabs(area)<EPS){
		puts("-1.000");	continue;
	}

	printf("%.3f\n",area);
}




return 0;
}

