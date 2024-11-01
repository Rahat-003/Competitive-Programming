#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

struct point{
    ll x,y;
    point(){};
    point(ll a,ll b){
        x = a;  y = b;
    }
};

ll fn(point s,point  t){
    ll a = s.x,b = s.y,c = t.x,d = t.y;

    if(a==c)    return abs(d-b);
    if(b==d){
        // source is always at top
        if((a+b)%2==0){
            ll p = abs(a-c);
            if(p%2==0)  return p*2;
            else return (p*2-1);
        }
        else{
            ll p = abs(a-c);
            if(p%2==0)  return 2*p;
            else return 2*p+1;
        }
    }
}

int main(){
int t,tc = 0;

point p,q;
while(cin>>p.x>>p.y>>q.x>>q.y){
        if(p.x==0 && p.y==0 && q.x==0 && q.y==0)    break;
    if(p.x>q.x) swap(p,q);
    q = point(q.x,p.y+abs(q.y-p.y));
    // destination is always at right
    point M = point(q.x,p.y),N;
    ll a = fn(p,M)+fn(M,q);
    ll d1 = abs(p.x-q.x),d2 = abs(p.y-q.y);
    ll mn = min(d1,d2);
    N = point(p.x+mn,p.y+mn);
    ll b = mn*2+fn(N,q);
    cout<<min(a,b)<<endl;
}



return 0;
}
