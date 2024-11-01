/*******************************
    n1m1 + n2m2 = n;

*******************************/

#include <cstdio>
typedef long long ll;
#include <cmath>

ll gcd(ll a,ll b,ll &x, ll &y){
    if(a==0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1,y1, g = gcd(b%a,a,x1,y1);
    y = x1;
    x = (g-b*y)/a;
    return g;
}

int main(){

ll n1,n2,n, c2 = 1, c1 = 1;
while(3==scanf("%lld %lld %lld",&n1,&n2,&n)){
    ll x,y,m1,m2,t1,t2,t;
    ll g = gcd(n1,n2,x,y);
    if(n%g!=0){
        puts("Impossible");
        continue;
    }
//    c/=g;
    t1 = ceil(-x*n/(double)n2), t2 = floor(y*n/(double)n1);
    if(t1>t2){
        puts("Impossible");
        continue;
    }
    /** if c1,c2 were given.. cost function would be
        cost1 = (c1*n2/g - c2*n1/g)*t1;
        cost2 = (c1*n2/g - c2*n1/g)*t2;
    */
    ll cost1 = t1*(n2-n1)/g;
    ll cost2 = t2*(n2-n1)/g;

    if(cost1<cost2) t = t1;
    else t = t2;

    m1 = x*n/g + n2/g*t;
    m2 = y*n/g - n1/g*t;
    printf("%lld %lld\n",m1,m2);
}





return 0;
}
