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

ll fn(ll n){
    ll x = (ll)sqrtl(n) - (ll)sqrtl(n/2);
    return x;
}


main(){
int t,tc = 0;

scanf("%d",&t);
while(t--){
    ll l,r;
    scanf("%lld%lld",&l,&r);
    ll ans = fn(r) - fn(l-1);
    case;
    printf("%lld\n",ans);
}


return 0;
}
