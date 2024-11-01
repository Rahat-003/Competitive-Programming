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
	void CIN(){
//		scanf("%lld %lld",&x,&y);
		cin>>x>>y;
		return;
	}
	bool operator == (const point &p)	const{
		return (p.x==x && p.y==y);
	}
	bool operator < (const point &p)	const{
		if(x==p.x)	return y<p.y;
		return x<p.x;
	}
	
};
struct line{
	point p,q;
	line(){};
	line(point a,point b){
		p = a,q = b;
	}
};
vector<point> v;
point mid(point s,point p){
	return point(2*s.x-p.x,2*s.y-p.y);
}

int main(){

int t;
scanf("%d",&t);

while(t--){
	int n;
	scanf("%d",&n);	
	if(n==1){
		puts("yes");
		continue;
	}
	for(int i = 0; i<n; i++){
		point a;	a.CIN();
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	line L;
	L.p = v[0];
	bool fl = true;
	
	for(int i = 1; i<v.size(); i++){
		fl = true;
		L.q = v[i];
		point S;
		S.x = (L.p.x+L.q.x)/2.0;
		S.y = (L.p.y+L.q.y)/2.0;
		
		for(int j = 0;j<v.size(); j++){
			if(j==i)	continue;
			point p = v[j];
			point q = mid(S,p);
			int id = lower_bound(v.begin(),v.end(),q) - v.begin();
			if( !(v[id]==q)){
			fl = false;
			break;
			}	
			
		}
		if(fl)	{
		puts("yes");	break;
		}
	}
	
	if(!fl) puts("no");
	
	v.clear();
}

return 0;
}

