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
#define pi acos(-1.0)

struct point{
    int x,y;
    point(){};
    point(int a,int b){
        x = a,y = b;
    }
};

int main(){

int n;

while(1==scanf("%d",&n)){
    if(!n)  break;

    int m = 1+(n/2);
    vector<point> v;
    for(int i = 0; i<n; i++){
        int a,b;    cin>>a>>b;
        point p(a,b);
        v.push_back(p);
    }
    int stan = 0,ollie = 0;
    point orig = v[m-1];

    for(int i = 0; i<v.size(); i++){
        point p = v[i];
        p.x-=orig.x,  p.y-=orig.y;
//        cout<<p.x<<" "<<p.y<<endl;
        if(p.x==0 || p.y==0)    continue;
        if( (p.x>0 && p.y>0)|| (p.x<0 && p.y<0) )   stan++;
        else ollie++;
    }
    v.clear();
   printf("%d %d\n",stan,ollie);
}

return 0;
}
