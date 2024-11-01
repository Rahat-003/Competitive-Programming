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

#define mx 10001
vector<ll> v;

int main(){
int t,tc = 0;

for(ll i = 0; i<mx; i++)    v.push_back(i*i*i);
ll n;
while(1==scanf("%lld",&n)){
    if(!n)  break;
    ll id;
    id = lower_bound(v.begin(),v.end(),n) - v.begin();
    ll x = -1,y;
    for(ll i = id; i<mx; i++){
        ll p = v[i]-n;  ll j;
        j = lower_bound(v.begin(),v.end(),p) - v.begin();
        if(j==v.size()) continue;
        if(v[j]==p && p!=0){
            x = i;  y = j;
            break;
        }
    }
    if(x!=-1)   printf("%lld %lld\n",x,y);
    else puts("No solution");

}


return 0;
}
