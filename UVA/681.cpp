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
struct point{
	double x,y;
	point(){};
	point(double a,double b){
		x = a, y = b;
	}
	bool operator == (const point &p)	const{
	return x==p.x && y==p.y;
	}
};
struct vec{
	double a,b;
	vec(){};
	vec(double x,double y){
		a = x, b = y;
	}
};
double degToRad(double x){
	return pi*x/180.0;
}
double radToDeg(double x){
	return x*180.0/pi;
}

vec toVec(point a,point b){
	return vec(b.x-a.x,b.y-a.y);
}
double cross(vec x,vec y){
	return x.a*y.b-x.b*y.a;
}

double orientation(point p,point q,point r){
	double o = cross(toVec(p,q),toVec(p,r));
	if(o==0)	return 0;
	if(o>0)		return -1;
	return 1;
}
double dist(point p,point q){
	return hypot(p.x-q.x,p.y-q.y);
}

point pivot;
bool cmp(point a,point b){
	double z = orientation(pivot,a,b);
	if(z==0){
		return (dist(pivot,a)<dist(pivot,b));
	}
	double x1 = a.x-pivot.x, y1 = a.y - pivot.y;
	double x2 = b.x-pivot.x, y2 = b.y - pivot.y;
	return ( (atan2(y1,x1)-atan2(y2,x2) )<0 );
}
vector<point> P,S,TT;
void SORT(){
	if(P.size()<=3){
		if( !(P[0]==P[P.size()-1]))	P.push_back(P[0]);
		return;
	}
	int id = 0;
	for(int i = 1; i<P.size(); i++){
		if( P[i].y<P[id].y || (P[i].y==P[id].y && P[i].x<P[id].x) )		id = i;
	}
	swap(P[0],P[id]);
	pivot = P[0];
	
	sort(P.begin()+1,P.end(),cmp);
}
void hull(){
	int sz = P.size();
	S.push_back(P[sz-1]);	S.push_back(P[0]);	S.push_back(P[1]);
	int i = 2;
	while(i<sz){
		int j = S.size()-1;
		double o1 = orientation(S[j-1],S[j],P[i]);
		if(o1<0)	S.push_back(P[i++]);
		else	S.pop_back();
	}
}


int main(){

int n,t;

cin>>t;

int g = t;

while(t--){
	if(g==t+1)	cout<<g<<endl;
	cin>>n;
	while(n--){
		double x,y;	cin>>x>>y;
		P.push_back(point(x,y));
	}
	int x;
	if(t)	cin>>x;
	
	SORT();
	hull();
	cout<<S.size()<<endl;
	for(int i = 1; i<S.size(); i++)
		cout<<S[i].x<<" "<<S[i].y<<endl;
		cout<<pivot.x<<" "<<pivot.y<<endl;

	S.clear();	P.clear();
	if(t)	cout<<x<<endl;
	
}

return 0;
}

