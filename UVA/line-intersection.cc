#include <cstdio>
#include <algorithm>
using namespace std;

struct point{
int x,y;
};

struct line{
point a,b;
};

int orientation(point a,point b,point c){
return (a.y-b.y)*(b.x-c.x)-(a.x-b.x)*(b.y-c.y);
}

bool seg(point a,point b,point c){
return ( (max(a.x,b.x)>=c.x) && (min(a.x,b.x)<=c.x) && (max(a.y,b.y)>=c.y) && (min(a.y,b.y)<=c.y) );
}

bool check(line l1,line l2){
int o1=orientation(l1.a,l1.b,l2.a);
int o2=orientation(l1.a,l1.b,l2.b);
int o3=orientation(l2.a,l2.b,l1.a);
int o4=orientation(l2.a,l2.b,l1.b);

if(o1!=o2&&o3!=o4)
    return true;
if(!o1) return(seg(l1.a,l1.b,l2.a));
if(!o2) return (seg(l1.a,l1.b,l2.b));
if(!o3) return (seg(l2.a,l2.b,l1.a));
if(!o4) return (seg(l2.a,l2.b,l1.b));
return false;

}

int main(){

line line1,line2;
scanf("%d %d %d %d",&line1.a.x,&line1.a.y,&line1.b.x,&line1.b.y);
scanf("%d %d %d %d",&line2.a.x,&line2.a.y,&line2.b.x,&line2.b.y);
printf("%d\n",check(line1,line2));

return 0;
}
