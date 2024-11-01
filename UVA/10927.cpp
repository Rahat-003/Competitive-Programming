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
typedef pair<double,double> pp;
struct point{
    double x,y,z,angle;
    point(){};
    point(double a,double b,double _z,double c){
        x = a,y = b,z = _z,angle = c;
    }
    bool operator<(const point &p)  const{
        if(angle!=p.angle)  return angle<p.angle;
      /*
        if(x!=p.x){
    if(x<0 && p.x<0)  return true;
    if(x>0 && p.x>0)  return true;
    }
    else{
        if(y<0 && p.y<0)  return true;
        if(y>0 && p.y>0)  return true;
    }
    */
        return hypot(x,y)<hypot(p.x,p.y);
    }
};

bool sign(point a,point b){
    if(a.x!=b.x){
    if(a.x<0 && b.x<0)  return true;
    if(a.x>0 && b.x>0)  return true;
    }
    else{
        if(a.y<0 && b.y<0)  return true;
        if(a.y>0 && b.y>0)  return true;
    }

    return false;
}


int main(){
//    read;
int e;
int tc = 0;
while(cin>>e){
    if(!e)  break;
    vector<point> P;
    vector<pp> Q;
    for(int i = 0; i<e; i++){
        double x,y,z; cin>>x>>y>>z;
        P.push_back(point(x,y,z,atan2(y,x)));
    }
    sort(P.begin(),P.end());
    double mz = P[0].z;

    for(int i = 1; i<P.size(); i++){
        point A = P[i-1],   B = P[i];
        if(A.angle!=B.angle){
            mz = B.z;
        }
        else{
            if(B.z<=mz) Q.push_back(pp(B.x,B.y));
            else mz = B.z;
        }
    }
    printf("Data set %d:\n",++tc);
    sort(Q.begin(),Q.end());
    if(Q.size()){
     puts("Some lights are not visible:");

    for(int i = 0; i<Q.size(); i++){
            if(i)   puts(";");
        printf("x = %d, y = %d",(int)Q[i].first,(int)Q[i].second);
    }
    puts(".");
    }
    else puts("All the lights are visible.") ;
}




return 0;
}

