#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;

double round(double x){	return ((floor(x*10000.0+.5)/10000.0));}

#define pi acos(-1.0)

int main(){

int t;
cin>>t;

	cin.ignore();
while(t--){
	vector<double> v;
	v.clear();
	string s;	getline(cin,s);
	istringstream iss(s);
	double a,r1,r2,t,b,c,R,area;	while(iss>>a)	v.push_back(a);
	
	if(v.size()==1){
		t = v[0];
		R = t/2.0;
		r1 = R/2.0;
		area = pi*R*R-2*pi*r1*r1;
	}	
	else{
	r1 = v[0],r2 = v[1];
	R = (r1+r2);
	area = pi*R*R-pi*r1*r1-pi*r2*r2;
	}
	printf("%.4f\n",round(area));
	
}



return 0;
}

