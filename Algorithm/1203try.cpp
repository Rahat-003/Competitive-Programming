#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
#define mx 100005
struct point{
    double x,y;
    bool operator<(const point &n)  const{
        return (x<n.x || (x==n.x && y<n.y));
    }
};
vector<point> v;
point ar[mx];
int n;

int cross_product(point a,point b,point c){
    double p = (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
    if(p>0) return 1;
    if(p<0) return -1;
    return 0;
}
void fn(){
    if(n<=3){
        for(int i = 0; i<n; i++)
            v.push_back(ar[i]);
        return;
    }
    v = vector<point> (2*n);
    sort(ar,ar+n);
    int k = 0;
    for(int i = 0; i<n; i++){
        while(k>=2 && cross_product(v[k-2],v[k-1],ar[i])<=0)    k--;
        v[k++] = ar[i];
    }
    for(int i = n-1,j = k+1; i; i--){
        while(k>=j && cross_product(v[k-2],v[k-1],ar[i-1])<=0)  k--;
        v[k++] = ar[i-1];
    }
    v.resize(k-1);
}

double dist(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double ff(point a,point b,point c){
    double x,y,z;
    x = dist(a,b),y = dist(b,c),z = dist(c,a);

    double p = (x*x+y*y-z*z)/(2.0*x*y);
    p = acos(p)*180.0/pi;
//    cout<<p<<endl;
    return p;
}

main(){
int t,tc = 0;
read;
scanf("%d",&t);

while(t--){
    scanf("%d",&n);
    v.clear();
    for(int i = 0; i<n; i++)    scanf("%lf%lf",&ar[i].x,&ar[i].y);
    fn();
    double ans = 1000.0;
    case;
    if(v.size()<=2){
        puts("0");
        continue;
    }
    int sz = v.size();
    for(int i = 0; i<v.size(); i++){
        point a = v[(i-1+sz)%sz],b = v[i],c = v[(i+1)%sz];
        ans = min(ans,ff(a,b,c));
    }
    printf("%.6f\n",ans);
}

return 0;
}
