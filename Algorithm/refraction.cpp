#include <cstdio>
#include <math.h>
#include <iostream>
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
using namespace std;
#define pi acos(-1)

#define EPS 1e-10
double W,H,x,xe,ye,miu;

double degtorad(double x){
    return x*pi/180.0;
}
double radtodeg(double x){
    return x*180.0/pi;
}

int go(double xp,double yp){
     double alpha,bita,gama,q;
     if(fabs(yp)<EPS)   bita = pi/2.0;
     else bita = atan((xp-x)/yp);
     alpha = asin(sin(bita)*miu);
     gama = 90.0 - radtodeg(alpha);
     if(fabs(alpha)<EPS)    return 1;
     q = yp + (xe-xp)*tan(degtorad(gama));
     if(fabs(q-ye)<EPS)   return 2;
     if( q>ye )   return 1;
     return 0;
}

bool check(double h){
    double p;
    p = W - ((H-h)*(xe-W)/(ye-H));
    double l = x,r = p,m1,m2;
    if(p<x)     return false;
    int f1 = go(l,h),f2 = go(r,h);
    if(f1==2 || f2==2)  return 1;
    if(f1==1 && f2==0)  return 1;
    return false;
}


main(){
//read;
//write;
int t;
scanf("%d",&t);

while(t--){
    scanf("%lf%lf%lf%lf%lf%lf",&W,&H,&x,&xe,&ye,&miu);
    double l = 0.0,r = H,m,ans;
    bool fl = 0;
    for(int i = 0; i<30; i++){
        m = (l+r)/2.0;
        if(check(m))    r = m,ans = m,fl = 1;
        else l = m;
    }
    if(fl==false){
        puts("Impossible");
        continue;
    }
    printf("%.4f\n",ans);
}

return 0;
}

