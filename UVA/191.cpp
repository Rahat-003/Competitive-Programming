#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <iostream>
#include <algorithm>
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("print.txt","w",stdout)
typedef long long ll;
using namespace std;

struct point{
    int x,y;
    point(){};

};

struct line{
    point p,q;
    line(){};
    line(int x1,int y1,int x2,int y2){
    	p.x = x1;
    	p.y = y1;
    	q.x = x2,q.y = y2;
	}
};

int orientation(point a,point b,point c){
    int ans = (b.y-a.y)*(c.x-b.x)-(c.y-b.y)*(b.x-a.x);
    if(ans==0)  return 0;
    if(ans>0)   return 1;
    return 2;
}

bool seg(point a,point b,point c){
    return  (c.x<=max(a.x,b.x) && min(a.x,b.x)<=c.x && c.y<=max(a.y,b.y) && min(a.y,b.y)<=c.y);
}

bool check(line l1,line l2){
	point a = l1.p, b = l1.q, c = l2.p, d = l2.q;

    int o1 = orientation(a,b,c);
    int o2 = orientation(a,b,d);
    int o3 = orientation(c,d,a);
    int o4 = orientation(c,d,b);

    if(o1!=o2 && o3!=o4)    return true;

    if(!o1 && seg(a,b,c)) return true;
    if(!o2 && seg(a,b,d)) return true;
    if(!o3 && seg(c,d,a)) return true;
    if(!o4 && seg(c,d,b)) return true;
    return false;
}

vector<line> v;
bool make(int ltx,int lty,int rbx,int rby,line L){

	v.push_back(line(ltx,lty,rbx,lty));
	v.push_back(line(ltx,lty,ltx,rby));
	v.push_back(line(rbx,rby,ltx,rby));
	v.push_back(line(rbx,rby,rbx,lty));

	for(int i = 0; i<v.size(); i++){
		line M = v[i];
		if(check(L,M))	return true;
	}
	return (L.p.x>=ltx && L.q.x>=ltx && L.p.x<=rbx && L.q.x<=rbx && L.p.y<=lty && L.q.y<=lty && L.p.y>=rby && L.q.y>=rby);

	return false;
}


int main(){
//read;

int t;

scanf("%d",&t);
while(t--){
line line1,line2;
	int a,b,c,d;
scanf("%d %d %d %d",&line1.p.x,&line1.p.y,&line1.q.x,&line1.q.y);

scanf("%d %d %d %d",&a,&b,&c,&d);
if(a>c){
    swap(a,c);
}
if(b<d){
    swap(b,d);
}

bool fl = make(a,b,c,d,line1);
if(!fl)	puts("F");
else puts("T");
v.clear();
}

return 0;
}


