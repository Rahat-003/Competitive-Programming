/*****

    (a*b)%c
    taking a*b may overflow
*****/

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

ll fn(ll a,ll b,ll c){
    ll x = 0,y = a%c;
    while(b>0){
        if(b%2==1){
            x = (x+y)%c;
        }
        y = (2*y)%c;
        b/=2;
    }
    return x%c;
}

int main(){
int t,tc = 0;

ll a,b,c;
while(cin>>a>>b>>c) cout<<fn(a,b,c)<<endl;


return 0;
}
