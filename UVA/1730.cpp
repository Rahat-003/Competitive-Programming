#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d:",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef unsigned long long ll;
using namespace std;
#define pi acos(-1)
#define mx (ll)2e7+2
ll ar[mx];

void bal(){
    for(ll i = 2; i<mx; i++){
        for(ll j = i; j<mx; j+=i){
            ar[j]+=i;
        }
        ar[i]++;
        ar[i]+=ar[i-1];
    }
}

int main(){
int t,tc = 0;
bal();
ll n;
while(1==scanf("%llu",&n)){
    if(!n)  break;
    printf("%llu\n",ar[n]);
}


return 0;
}

