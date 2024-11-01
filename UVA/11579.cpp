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

	
vector<double> v;
double go(){
	double T = 0;
	for(int i = 2; i<v.size(); i++){
		double	c = v[i-2],b,a;
		b = v[i-1];
		a = v[i];
		if(a+b>c){
			double s = (a+b+c)/2.0,		area = sqrt(s*(s-a)*(s-b)*(s-c));	
			T = max(T,area);
		}	
	}
		return	T;
}
double round(double x){
	x = (floor(x*100.0+.5))/100.0;
	return x;
}

int main(){
int t;
cin>>t;
while(t--){
	v.clear();
	int e;	cin>>e;
	while(e--)	{
		double n;	cin>>n;	v.push_back(n);
	}
	sort(v.begin(),v.end(),greater<double>());
	double area = go();
	
	printf("%.2f\n",round(area));
}

return 0;
}

