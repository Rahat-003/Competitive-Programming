#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define mx 30000001

ll ar[mx];

void fn(){
    ll x = 0;

    for(ll i = 1; i<mx; i++){
        for(ll j = i+i; j<mx; j+=i){
            ll k = i^j;
            if(k>j || k%i!=0) continue;
            ar[j]++;
        }
        ar[i]+=ar[i-1];
    }
}


main(){
int t,tc = 0;
fn();
scanf("%d",&t);
while(t--){
    int n;
    scanf("%d",&n);
    case;
    printf("%lld\n",ar[n]);
}

return 0;
}
