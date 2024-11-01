#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

void cal(int mark,double A,double B,double C,double &x,double &y){

    double u,v,a,s,t;
    if(mark==1){
        u = A,v = B,t = C;
        y = (v-u)/t;
        x = u*t + .5*y*t*t; return;
    }
    if(mark==2){
        x = (B*B-A*A)/2;
        x/=C;
        y = (B-A)/C;   return;
    }
    if(mark==3){
        x = A*A+2*B*C;
        x = sqrt(x);
        double avg = (x+A)/2;
        y = C/avg;
        return;
    }
    if(mark==4){
        x = A*A-2*B*C;
        x = sqrt(x);
        double avg = (x+A)/2;
        y = C/avg;
        return;
    }

}


int main(){
int n,tc = 0;
double p,q,r,s;
while(1==scanf("%d",&n)){
    if(!n)  break;
    double x,y;
    scanf("%lf %lf %lf",&p,&q,&r);
//    cin>>p>>q>>r;
    cal(n,p,q,r,x,y);
    printf("Case %d: ",++tc);
    cout<<fixed<<setprecision(3)<<x<<" "<<y<<'\n';
}



return 0;
}
