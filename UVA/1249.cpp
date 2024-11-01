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
    point(double a,double b){x = a,y = b;}
};

double dist(point a,point b){
    return hypot(a.x-b.x,a.y-b.y);
}

double area(point a,point b,point c){
    double s =( dist(a,b)+ dist(b,c)+dist(c,a) )/2.0;
    return sqrt(s*(s-dist(a,b))*(s-dist(b,c))*( s-dist(c,a) ) );
}

int main(){
//double ax,ay,bx,cx,dx,ex,fx,gx,hx,by,cy,dy,ey,fy,gy,hy;
point a,b,c,d,e,f,g,h;

while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y>>e.x>>e.y>>f.x>>f.y){
    if(!a.x && !b.x && !c.x && !d.x && !e.x && !f.x && !a.y && !b.y && !c.y && !d.y && !e.y && !f.y) break;
        double tri = area(d,e,f),   m1,m2;
        double ab = dist(a,b),  ac = dist(a,c),     bc = dist(b,c);
        double height = tri/ab;
        double angCAB = acos((ab*ab+ac*ac-bc*bc)/(2*ab*ac));
        double ah = height/sin(angCAB);
        double hc = ac-ah;         m1 = ah,    m2 = hc;
        h.x = (m1*c.x+m2*a.x)/(m1+m2);
        h.y = (m1*c.y+m2*a.y)/(m1+m2);
        g.x = b.x+(h.x-a.x);
        g.y = b.y+(h.y-a.y);
//        cout<<g.x<<" "<<g.y<<" "<<h.x<<" "<<h.y<<endl;
        printf("%.3f %.3f %.3f %.3f\n",g.x,g.y,h.x,h.y);
}

return 0;
}
