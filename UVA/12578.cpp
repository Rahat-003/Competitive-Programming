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

double round(double x){	return ((floor(x*100.0+.5)/100.0));
}

int main(){
int t;
cin>>t;

while(t--){
	double l,b,r,cir,rest;	cin>>l;
	b = l*6/10.0;
	r = 2*l/10.0;
	cir = pi*r*r;
	rest = l*b-cir;
	printf("%.2f %.2f\n",round(cir),round(rest));
}

return 0;
}

