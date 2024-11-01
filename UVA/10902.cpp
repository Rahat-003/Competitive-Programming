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
	bool CIN(){
		cin>>x>>y;	return true;
	}
	
};
struct eqn{
	double a,b,c;
	eqn(){};
	eqn(double x,double y,double z){
		a = x,b = y,c = z;
	}
	bool scn(){
		cin>>a>>b>>c;	return true;
	}
	bool check(){	return (!a && !b && !c);
	}
};
struct line{
	point a,b;
	line(){};
	line(point c,point d){
		a = c,b = d;
	}
};
vector<line> v;

eqn pointsToEqn(point a,point b){
	eqn E;
	E.a = -(a.y-b.y);
	E.b = 	(a.x-b.x);
	E.c = a.x*E.a+E.b*a.y;
	return E;
}
#define EPS (double)1e-12
bool intersect(point a,point b,point c,point d){
	double x1 = a.x<b.x?a.x:b.x,	y1 = a.y<b.y?a.y:b.y;
	double x2 = a.x>b.x?a.x:b.x,	y2 = a.y>b.y?a.y:b.y;
	
	double x3 = c.x<d.x?c.x:d.x,	y3 = c.y<d.y?c.y:d.y;
	double x4 = c.x>d.x?c.x:d.x,	y4 = c.y>d.y?c.y:d.y;
	
	eqn one = pointsToEqn(a,b);
	eqn two = pointsToEqn(c,d);
	double det = one.a*two.b-one.b*two.a;
	if(fabs(det)<EPS)	return false;
//	if()	
	double x = (one.c*two.b-two.c*one.b)/det;
	double y = (one.a*two.c-one.c*two.a)/det;	
	return (x1<=x && x<=x2 && y1<=y && y<=y2 && x3<=x && x<=x4 && y3<=y && y<=y4);
	
}

int main(){
point a,b,c,d;
int n;
while(cin>>n){	
	if(n==0)	break;
	bool ar[n+3];
//	memset(ar,true,sizeof ar);
	for(int i = 0; i<n; i++){
		ar[i] = true;
	a.CIN(); b.CIN(); // && c.CIN() && d.CIN();
	v.push_back(line(a,b));
	}
	
	vector<int> ans;
	for(int  i = 0; i<n; i++){
		for(int j = i+1; j<v.size(); j++){
			if(intersect(v[i].a,v[i].b,v[j].a,v[j].b)){
			ar[i] = false;
			break;
			}	
		}
		if(ar[i])	ans.push_back(i+1);
	}
	printf("Top sticks:");
	for(int i = 0 ; i<ans.size(); i++){
		printf(" ");
		printf("%d",ans[i]);
		if(i==ans.size()-1)	printf(".\n");
		else printf(",");
	}
	v.clear();
}


return 0;
}

