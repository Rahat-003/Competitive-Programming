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

#define pi acos(-1)

int main(){

int t,tc = 0;

cin>>t;

while(t--){
    double r1,r2,con,cyl,r4,r3,p,h,cr,ans;
    cin>>r1>>r2>>h>>p;
    double x = r1-r2;
    double theta = atan2(h,x),  alpha = pi-theta;
    double pr = r2+p*tan(pi/2-theta);
    double H = pr/tan(pi/2-theta);
    ans = pi*pr*pr*H/3.0-pi*r2*r2*(H-p)/3.0;
    ans = fabs(ans);
    printf("Case %d: %.6f\n",++tc,ans);

//    cout<<ans<<endl;

}




return 0;
}

