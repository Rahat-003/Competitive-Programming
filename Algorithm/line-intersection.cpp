#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;

struct point{
    double x,y;
    point(){};
    point(double a,double b){
    x = a,y = b;
    }
};
double dist(point a,point b){
//	return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
	return hypot(b.x-a.x,b.y-a.y);
}
bool onsegment(point a,point b,point c){
	if(dist(a,b)==(dist(a,c)+dist(b,c)))	return true;
	return false;
}
/*
bool onsegment(point a,point b,point c){
    double xmin = min(a.x,b.x),  ymin = min(a.y,b.y);
    double xmax = max(a.x,b.x),  ymax = max(a.y,b.y);
    return (xmin<=c.x && c.x<=xmax && ymin<=c.y && c.y<=ymax);
}
*/
double orientation(point p,point q,point r){
    double ans = (q.x-p.x)*(r.y-q.y)-(q.y-p.y)*(r.x-q.x);
    if(ans==0)  return 0;
    if(ans>0)   return 1;
    return -1;
}

bool lineSegmentIntersect(point a,point b,point c,point d){
    double o1 = orientation(a,b,c);
    double o2 = orientation(a,b,d);
    double o3 = orientation(c,d,a);
    double o4 = orientation(c,d,b);
    if(o1!=o2 && o3!=o4)    return true;

    if(!o1 && onsegment(a,b,c)) return true;
    if(!o2 && onsegment(a,b,d)) return true;
    if(!o3 && onsegment(c,d,a)) return true;
    if(!o4 && onsegment(c,d,b)) return true;
    return false;
}

int main(){
point p,q,r,s;
while(cin>>p.x>>p.y>>q.x>>q.y>>r.x>>r.y/*>>s.x>>s.y*/ ){
//    cout<<lineSegmentIntersect(p,q,r,s)<<endl;
    cout<<orientation(p,q,r)<<endl;

}




return 0;
}

