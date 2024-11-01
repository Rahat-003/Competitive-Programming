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
#define EPS (double)1e-11
struct point{
double x,y;
point(){};
point(double a,double b){x = a,y = b;}
};

struct eqn{
    double a,b,c;
    eqn(){};
    eqn(double p,double q,double r){a = p,b = q,c = r;}
};

eqn pointsToEqn(point a,point b){
    double x1= a.x, y1 = a.y;
    double x2 = b.x, y2 = b.y;
    eqn E;
    E.a = -(y1-y2);
    E.b = x1 - x2;
    E.c = (E.a*a.x)+E.b*a.y;
    return E;
}

eqn perp(eqn one,point p){
    eqn E;
    E.a = one.b;
    E.b = -one.a;
    E.c = E.a*p.x+E.b*p.y;
    return E;
}
double dist(point a,point b){
    return hypot(a.x-b.x,a.y-b.y);
}

bool fy(eqn one,double diagonal,point &t1,point &t2,point mid){

//    return ( (one.c-one.a*x)/one.b);
    if(fabs(one.b)<EPS){
        t1.x = t2.x = mid.x;
        t1.y = mid.x+diagonal/2.0;
        t2.y = mid.x-diagonal/2.0;
        return true;
    }
    if(fabs(one.a)<EPS){
        t1.y = t2.y = mid.y;
        t1.x = mid.x+diagonal/2.0;
        t2.x = mid.x - diagonal/2.0;
        return true;
    }
    t1.x = mid.x - diagonal;
    t1.y = (one.c - one.a*t1.x)/one.b;;
    t2.x = mid.x+diagonal;
    t2.y = (one.c-one.a*t2.x)/one.b;
return false;
}

point bsearch(point L,point U,double cmp,point m){
    point p,q;
    p.x = (L.x+U.x)/2.0;
    p.y = (L.y+U.y)/2.0;
    double d = dist(p,m);
    if( fabs(d-cmp)<EPS )  return p;

    if(d>cmp)   return bsearch(p,U,cmp,m);
    if(d<cmp)   return bsearch(L,p,cmp,m);
}

void print(point a,point b){
    printf("%.10f %.10f %.10f %.10f\n",a.x,a.y,b.x,b.y);
}

int main(){
point B,D;
while(cin>>B.x>>B.y>>D.x>>D.y){
        if(B.x==D.x && D.y==B.y){
            puts("Impossible");
            continue;
        }
point E;
    E.x = (B.x+D.x)/2;
    E.y = (B.y+D.y)/2;
    double diagonal = dist(B,D);

        if(B.y==D.y){
            point A,C;
//            cout<<E.x<<" "<<E.y<<" "<<diagonal<<endl;
            A.x= E.x;   A.y = E.y+diagonal/2.0;
            C.x = E.x; C.y = E.y-diagonal/2.0;
            print(A,C);
            continue;
        }
    if(B.x==D.x){
        point A,C;
        A.y = E.y; A.x = E.x + diagonal/2.0;
        C.y = E.y; C.x = E.x - diagonal/2.0;
        print(A,C);
        continue;
    }

    eqn BD = pointsToEqn(B,D);
    eqn AC = perp(BD,E);

    point test1,test2;
//    test.x = E.x - diagonal;
    bool fl = fy(AC,diagonal,test1,test2,E);
    double cmp = diagonal/2.0;
    if(fl)  print(test1,test2);
    else{
        point A = bsearch(test1,E,cmp,E);
        point C ;
        C.x = (E.x*2) - A.x;
        C.y = (E.y*2) - A.y;
        print(A,C);
    }
}



return 0;
}
