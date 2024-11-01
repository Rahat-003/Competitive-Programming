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

#define EPS (double)1e-12

struct point{
    double x,y;
    point(){};
    point(double a,double b){x = a,y = b;}
};

struct eqn{
    double a,b,c;
    eqn(){};
    eqn(double p,double q,double r){a=p,b = q,c = r;}
};
eqn pointsToEqn(point p,point q){
    double x1 = p.x, y1 = p.y;
    double x2 = q.x, y2 = q.y;
    eqn E;
    E.a = -(y1-y2);
    E.b =   x1-x2;
    E.c = E.a*x1+E.b*y1;
    return E;
}
int orientation(point a,point b,point c){
    double ans = (b.y-a.y)*(c.x-b.x)-(c.y-b.y)*(b.x-a.x);
    if(ans==0)  return 0;
    return (ans>0)? 1:2;
}

int intersect(point p1,point p2,point p3,point p4,point &p){
    eqn one = pointsToEqn(p1,p2);
    eqn two = pointsToEqn(p3,p4);
    double a1 = one.a, b1 = one.b, c1 = one.c;
    double a2 = two.a, b2 = two.b, c2 = two.c;
    double det = a1*b2-b1*a2;

    if(det==0){
        int o1 = orientation(p1,p2,p3);
        int o2 = orientation(p1,p2,p4);
        int o3 = orientation(p3,p4,p1);
        int o4 = orientation(p3,p4,p2);
        if(!o1 && !o2 &&  !o3 && !o4)   return 1;
        return 2;

    }
    p.x = (c1*b2-b1*c2)/det;
    p.y = (a1*c2-c1*a2)/det;

    return 3;
}

int main(){

int t;
scanf("%d",&t);
puts("INTERSECTING LINES OUTPUT");
while(t--){
    point p1,p2,p3,p4;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y,&p4.x,&p4.y);
    point ans;
    int fl = intersect(p1,p2,p3,p4,ans);
    if(fl==1)   puts("LINE");
    if(fl==2)   puts("NONE");
    if(fl==3)  {
    printf("POINT ");
    printf("%.2f %.2f\n",ans.x,ans.y);
    }

}
puts("END OF OUTPUT");


return 0;
}

