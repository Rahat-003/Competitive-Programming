#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
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

    bool operator == (const point &p1)  const{
        return (p1.x==x && p1.y==y);
    }
};

int main(){

point a,b,c;
double m,n;
point H,I;
while(cin>>a.x>>a.y>>b.x>>b.y>>H.x>>H.y>>c.x>>c.y){

    if(a==b){
        a = H;
    }
   else if(a==H){
        a = b;
        b = H;
    }
   else if(a==c){
        a = b;
        b = c;
        c = H;
    }
   else if(b==H){
        b = H;
    }

   else if(b==c){
        c=H;
    }

   else if(H==c){
        c = b;
        b = H;
    }
//    cout<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<" "<<c.x<<" "<<c.y<<endl;

    m = (a.x+c.x)/2.0;
    n = (a.y+c.y)/2.0;
    double X,Y;
    X = 2.0*m-b.x;
    Y = 2.0*n-b.y;
    printf("%.3f %.3f\n",X,Y);
}


return 0;
}
