#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef uint64_t ll;
using namespace std;
#define pi acos(-1)

bool check(ll n,ll i){
    return n&(1LL<<i);
}
ll Set(ll n,ll i){
    return n|(1LL<<i);
}

ll reset(ll n,ll i){
    return n&=~(1LL<<i);
}

int main(){
int t,tc = 0;
scanf("%d",&t);

while(t--){
    ll a,b;

    cin>>a>>b;
    ll p = a;
    ll  x = 0;///or
    ll y = a&b;
    for(ll i = 0; i<61; i++){
        if(!check(p,i)){
            p = Set(p,i);
            if(a<=p && p<=b){
             x = Set(x,i);
            }
        }
        else x = Set(x,i);
        p = reset(p,i);
    }
    p = b;
    for(ll i = 0; i<60; i++){
        if(check(y,i)){
            p = reset(p,i);
            if(a<=p && p<=b){
                y = reset(y,i);
            }
        }

    }
    printf("Case %d: ",++tc);
    cout<<x<<" "<<y<<endl;
}


return 0;
}
