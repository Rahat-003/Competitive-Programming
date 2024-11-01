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

struct point{
	double x,y;
	point(){};
	point(double a,double b){
		x = a,y = b;
	}
	bool operator < (const point &p)	const{
	return x<p.x;
	}
};
struct light{
	point p,q;
	double c;
	light(){};
	light(point a,point b,double x){
		p = a,q = b,c = x;
	}
};
vector<light> v;
vector<point> P;

bool check(double x1,double x2,double x3,double x4){
	if(x1>x2)	swap(x1,x2);
	if(x3>x4)	swap(x3,x4);
	if(x3<x1 && x4>=x2)	return true;
	if(x1==x3)	return true;
	if(x2==x4)	return true;
	if( (x1<x3 && x3<x2) || (x1<x4 && x4<x2) )	return true;
	return false;
}

int main(){
int t;
scanf("%d",&t);

while(t--){
	int e;
	cin>>e;
	while(e--){
		point a,b;
		cin>>a.x>>a.y>>b.x>>b.y;
		double c;	cin>>c;
		P.push_back(a);
		P.push_back(b);
		v.push_back(light(a,b,c));
	}
	sort(P.begin(),P.end());
	cout<<P.size()+1<<endl;	
	printf("-inf %.3f 1.000\n",P[0].x);
	for(int i = 1; i<P.size(); i++){
		double x1 = P[i-1].x;
		double x2 = P[i].x;
		double ans = 1.0;
		for(int j = 0; j<v.size(); j++){
			double a1 = v[j].p.x; // b1 = v[j].p.y;
			double a2 = v[j].q.x; //b2 = v[j].q.y;
			if(check(x1,x2,a1,a2) ){
			ans*=v[j].c;
			}	
		}
		printf("%.3f %.3f %.3f\n",x1,x2,ans);
	}	
	printf("%.3f +inf 1.000\n",P[P.size()-1].x);
	
	v.clear();	P.clear();

if(t)	puts("");
}

return 0;
}

