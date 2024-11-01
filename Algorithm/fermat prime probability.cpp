/***
    Carmichael numbers: 561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041...
    From 1 to 10^9 there is 646 Carmichael numbers
    maximum time e wrong ans dey
****/

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

ll bigmod(ll b,ll p,ll m){
    if(p==0)    return 1;
    if(p==1)    return p%m;
    ll x;
    if(p%2==0){
        x = bigmod(b,p/2,m)%m;
        return (x*x)%m;
    }
    return (b*bigmod(b,p-1,m))%m;
}

bool FermatPrimecheck(ll n){
    if(n<4) return n==2 || n==3;
    /// 10 iteration
    ll it = 10;
    for(ll i = 0; i<it; i++){
        ll a = 2+rand()%(n-3);
        if(bigmod(a,n-1,n)!=1)  return false;
    }
    return true;
}

int main(){
int t,tc = 0;

ll n;
while(1==scanf("%lld",&n)){
    bool fl = FermatPrimecheck(n);
    if(fl)  puts("Prime");
    else puts("Not Prime");
}


return 0;
}
