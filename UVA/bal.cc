#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d:",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
#define EPS 1e-10
struct point{
double x,y;
};
struct eqn{
    double a,b,c;
};
eqn pointsToEqn(point a,point b){
    eqn E;  double x1=a.x,y1 = a.y,x2=b.x,y2=b.y;
    E.a = -(y1-y2);
    E.b=x1-x2;
    E.c = (E.a*x1+E.b*y1);
    return E;
}

point intersect(eqn one,eqn two){
    point p;
    double det = one.a*two.b-one.b*two.a;
    p.x = (one.c*two.b-one.b*two.c)/det;
    p.y = (one.a*two.c-one.c*two.a)/det;
    return p;
}

eqn perp(eqn one,point a){
    eqn E;  E.a = one.b;    E.b = -one.a;   E.c=E.a*a.x+E.b*a.y;    return E;
}
double dist(point a,point b){
    return hypot(a.x-b.x,a.y-b.y);
}

double round(double a){
    a = (floor(a*1000.0+0.5))/1000.0;
    return a;
}
char cc(double a){
//    if(a==-0)    return '+';
    if(a>0)    return '-';
    return '+';
}
char bal(double a){
    if(a==0.000) return '+';
    if(a>=0)    return '+';
    return '-';
}

int main(){
    read;
int t,tc = 1;
point p,q,r;
while(cin>>p.x>>p.y>>q.x>>q.y>>r.x>>r.y){
    point mpq,mqr;
    mpq.x=(p.x+q.x)/2.0; mpq.y=(p.y+q.y)/2.0;
    mqr.x=(q.x+r.x)/2.0; mqr.y=(q.y+r.y)/2.0;
    point R = intersect(perp(pointsToEqn(p,q),mpq),perp(pointsToEqn(q,r),mqr));
//    R.x = round(R.x);   R.y=round(R.y);
    double rr = dist(R,p); // rr = round(rr);
//    if(tc)  puts("");
    if(round(R.x)){
    cout<<"(x "<<cc(R.x)<<" ";
    printf("%.3f)^2 + ",fabs(R.x));
    }
    else cout<<"x^2 + ";
    if(round(R.y)){
    cout<<"(y "<<cc(R.y)<<" ";
    printf("%.3f)^2",fabs(R.y));
    }
    else cout<<"y^2";
    if(round(rr))
        printf(" = %.3f^2\n",rr);
    else cout<<" = 0\n";
    /*
    cout<<")^2 + (y "<<cc(R.y)<<" ";
    printf("%.3f",fabs(R.y));
    cout<<")^2 = "; printf("%.3f",rr);
    cout<<"^2\n";
    */



//    + 2.000)^2 = 5.000^2"
    printf("x^2 + y^2");
    if(R.x)
    printf(" %c %.3fx",cc(R.x),fabs(2*R.x));
    if(R.y)
    printf(" %c %.3fy",cc(R.y),fabs(2*R.y));
    double y = R.x*R.x+R.y*R.y-rr*rr,z;
    z = round(y);
    /*
    if(z<=-1 || z>=1)   printf(" %c %.3f",cc(-z),fabs(z));
    else if(z>0 && z<1)    printf(" + 0.000");
    */
    if(fabs(z)<EPS)    printf(" + 0.000");
    else if(y<0) printf(" - %.3f",fabs(z));
    else if(y>0) printf(" + %.3f",fabs(z));


//    if(z==0)    puts("bal");
    /*
    if(z)
        printf(" %c %.3f",cc(-z),fabs(z));
    */
    printf(" = 0\n");
    puts("");
//    cout<<y<<endl;

}



return 0;
}

