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
};

struct vec{
	double a,b;
	vec(){};
	vec(double x,double y){
		a = x,b = y;
	}
};
vec toVec(point a,point b){
	return vec(b.x-a.x,b.y-a.y);
}
double cross(vec p,vec q){
	return (p.a*q.b-p.b*q.a);
}

double orientation(point p,point q,point r){
	if(p.x>q.x)	swap(p,q);
	double ans = cross(toVec(p,q),toVec(p,r));
	if(ans==0)	return 0;
	if(ans>0)	return 1;
	return -1;
}

double slope(point &p,point &q){
	if(p.x>q.x)	swap(p,q);
	double s = (p.y-q.y)/(p.x-q.x);
	return s;
	/*
	if(s>0)	return p;
	return q;
	*/
}
bool top(point s,point p,point q){
	double dhal = slope(p,q);
	double ans = orientation(p,q,s);
//	cout<<"orient "<<ans<<" dhal "<<dhal<<endl;	
	if(dhal<0 && ans<0)	return false;
	if(dhal>0 && ans<0)	return false;
	if(p.x>q.x)	swap(p,q);
	double y = (p.y>q.y)?q.y:p.y;
	if(s.y<y)	return false;
	if(s.x>=p.x && s.x<=q.x)	return true;
	return false;
}

struct line{
	point p,q;
	line(){};
	line(point a,point b){
		if(b.y<a.y)	swap(a,b);
		p = a,	q = b;
	}
	bool operator < (const line &l)	const{
		return q.y>l.q.y;
	}
};

int main(){
int t;
cin>>t;
/*
point a,b,c,d;
while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y){
//	cout<<slope(a,b).x<<" "<<slope(a,b).y<<endl;
	cout<<top(a,b,c)<<endl;
//	cout<<orientation(a,b,c)<<endl;
}
*/
while(t--){
	int e;	cin>>e;
	vector<line> v;
	while(e--){
			point p,q;
			cin>>p.x>>p.y>>q.x>>q.y;
		v.push_back(line(p,q));
	}
	cin>>e;
	vector<point> S;
	while(e--){
		point a;	cin>>a.x>>a.y;
		S.push_back(a);
	}
	sort(v.begin(),v.end());
	for(int i = 0; i<S.size();i++){
		bool fl = false;
		point M = S[i];
		for(int j = 0; j<v.size(); j++){
			point a = v[j].p, b = v[j].q;
			if( top(M,a,b) ){
				fl = true;
				if(slope(a,b)>0)	M = a;
				else 	M = b;
			}
		}
		cout<<M.x<<endl;
	}
	if(t)	puts("");

}




return 0;
}

