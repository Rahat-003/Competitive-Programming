/******
    999999999999999989 is a prime. But it returns false;

*******/
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

const ll excp = 999999999999999989ll;

ll bigmod(ll b,ll p,ll m){
    if(p==0)    return 1;
    if(p==1)    return b%m;
    ll x;
    if(p%2==0){
        x = bigmod(b,p/2,m)%m;
        return (x*x)%m;
    }
    return (b*bigmod(b,p-1,m))%m;
}

ll mulmod(ll a,ll b,ll c){
    ll x = 0,y = a%c;
    while(b>0){
        if(b&1) x = (x+y)%c;
        y = (2*y)%c;
        b/=2;
    }
    return x%c;
}

bool check(ll a,ll s,ll d,ll n){
    ll x = (bigmod(a,d,n)+n)%n;
    if(x==1 || x==n-1)  return true;

    for(ll i = 1; i<s; i++){
        x = (n+mulmod(x,x,n))%n;
//        x = (x*x)%n;
        if(x==n-1)  return true;
    }
    return false;
}

vector<ll> v = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

bool MillerRabin(ll n){
    if(n<4) return n==2 || n==3;
    if(n%2==0)  return false;

//    if(n==excp) return true;

    ll it = 100,s = 0,d = n-1;

    while(d%2==0){
        s++;
        d/=2;
    }
    ll a;

    for(ll i = 0; i<it; i++){
//    for(a:v){
        a = 2+rand()%(n-3);
        if(!check(a,s,d,n))  return false;
    }
    return true;
}

int main(){
int t,tc = 0;
scanf("%d",&t);
ll n;
while(t--){
    scanf("%lld",&n);
    if(MillerRabin(n))  puts("Prime");
    else puts("Not Prime");
}


return 0;
}
