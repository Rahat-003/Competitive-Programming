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

bool vis[102];

struct point{
	double x,y;
	point(){};
	point(double a,double b){
		x = a,y = b;
	}
};
struct line{
    point p,q;
    line(){};
    line(point a,point b){
    p = a,q = b;
    }
};

struct vec{
	double x,y;
	vec(){};
	vec(double a,double b){
		x = a,y = b;
	}
};
vec toVec(point a,point b){
	return vec(b.x-a.x,b.y-a.y);
}

double cross(vec a,vec b){
	return (a.x*b.y-a.y*b.x);
}
double orientation(point p,point q,point r){
	vec pq = toVec(p,q);
	vec pr = toVec(p,r);
	double x = cross(pq,pr);
	if(x==0)	return 0;
	if(x>0)		return 1;
	return -1;
}
/*

int orientation(point a,point b,point c){
    double ans = (b.y-a.y)*(c.x-b.x)-(c.y-b.y)*(b.x-a.x);
    if(ans==0)  return 0;
    return (ans>0)? 1:2;
}
*/


bool seg(point a,point b,point c){
    return  ( c.x<=(max(a.x,b.x)) && (min(a.x,b.x))<=c.x && c.y<=(max(a.y,b.y)) && (min(a.y,b.y))<=c.y );
}

bool check(point a,point b,point c,point d){
	double o1 = orientation(a,b,c);
	double o2 = orientation(a,b,d);
	double o3 = orientation(c,d,a);
	double o4 = orientation(c,d,b);
//	cout<<o1<<" "<<o2<<" "<<o3<<" "<<o4<<endl;
	if(o1!=o2 && o3!=o4)    return true;

	if(!o1 && seg(a,b,c)) return true;
    if(!o2 && seg(a,b,d)) return true;
    if(!o3 && seg(c,d,a)) return true;
    if(!o4 && seg(c,d,b)) return true;
    return false;
}


int main(){

int t;
cin>>t;
while(t--){
vector<line> v;
    int n;
    cin>>n;
    memset(vis,false,sizeof vis);
    while(n--){
        point a,b;
        cin>>a.x>>a.y>>b.x>>b.y;
        v.push_back(line(a,b));
    }
    int ans = 0;
    for(int i = 0; i<v.size(); i++){
        for(int j = i+1; j<v.size(); j++){
            line L1 = v[i];
            line L2 = v[j];
            if(check(L1.p,L1.q,L2.p,L2.q)){
                vis[i] = true;
                vis[j] = true;
            }
        }
    }
    for(int i = 0; i<v.size(); i++)
        if(!vis[i]) ans++;
    cout<<ans<<endl;

}

return 0;
}

