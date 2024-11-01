#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <iomanip>
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;

#define pi acos(-1)
struct point{
    double x,y;
    point(){};
    point(double a,double b){x = a, y = b;}
    bool operator == (const point &n1)   const{
        return (x==n1.x && y==n1.y);
    }
};
struct vec{
    double a,b;
    vec(){};
    vec(double x,double y){
    a = x,b = y;
    }
};
vector<point>P;

double dot(vec a,vec b){
    return (a.a*b.a+a.b*b.b);
}
vec toVec(point a,point b){
    return vec(b.x-a.x,b.y-a.y);
}
double cross(vec x,vec y){
    return (x.a*y.b-x.b*y.a);
}
bool ccw(point a,point b,point c){
    return ( cross(toVec(a,b),toVec(a,c) )>0 );
}
int orientation(point a,point b,point c){
    double ans = cross( toVec(a,b),toVec(a,c) );
    if(ans==0)  return 0;
   return ans>0?1:-1;
}

bool isConvex(){
if(P.size()<=3) return false;
    bool fl = ccw(P[0],P[1],P[2]);

    for(int i = 1; i<P.size() - 1; i++){
        if(fl!=ccw( P[i],P[i+1],P[ i+2==P.size()? 1 :i+2 ] ) )  return false;
    }
    return true;
}

double normal(vec p){
    return sqrt(p.a*p.a+p.b*p.b);
}

double radToDeg(double x){
    return x*180.0/(pi);
}

#define EPS (double)1e-6

double angle(point a,point b,point c){
    vec ab = toVec(b,a);
    vec bc = toVec(b,c);
    double p = dot(ab,bc)/(normal(ab)*normal(bc));
    if(fabs(1-p)<EPS)   return 0;
    if(fabs(-1-p)<EPS)  return 180;
    if(fabs(p)<EPS) return 90;
    double z = acos(p);
    return radToDeg(z);
}

bool isInside(point p){
    double ans = 0;// d = 360.0;
    for(int i = 0; i<P.size()-1; i++){
        if(P[i]==p || P[i+1]==p) return true;
        int o1 = orientation(P[i],p,P[i+1]);
        double x = angle(P[i],p,P[i+1]);
        if(o1>0)    ans+=x;
        else ans-=x;
    }
    ans = fabs(ans);
    double T = fabs(ans-360.0);
    if(T<EPS)   return true;
    return false;
}


int main(){

P.push_back(point (1, 1)); // P0
P.push_back(point (3, 3)); // P1
P.push_back(point (9, 1)); // P2
P.push_back(point(12, 4)); // P3
P.push_back(point (9, 7)); // P4
P.push_back(point (1, 7)); // P5
P.push_back        (P[0]);

point x;

while(cin>>x.x>>x.y){
    bool fl = isInside(x);
    cout<<fl<<endl;
}



return 0;
}
