
#include <cstdio>
#include <cmath>
typedef  long long ll;

ll gcd(ll a,ll b,ll &x, ll &y){
    if(a==0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1,y1;
    ll g = gcd(b%a,a,x1,y1);
    y = x1;
    x = (g-b*y)/a;
    return g;
}


int main(){
    freopen("tst.txt","r",stdin);

ll n;
while(1==scanf("%lld",&n)){
    if(!n)  break;
    ll c1,c2,n1,n2,_m1,_m2;
    scanf("%lld %lld %lld %lld",&c1,&n1,&c2,&n2);
    ll g = gcd(n1,n2,_m1,_m2);
    if(n%g!=0)  {
        puts("failed");
        continue;
    }
    ll t1 = ceil(-_m1*n/(double)n2);
    ll t2 = floor(_m2*n/(double)n1),t;

    if(t1>t2){
        puts("failed");
        continue;
    }

    ll cost1 = (n/g)*(c1*_m1+c2*_m2) +  t1*(c1*n2-c2*n1)/g;
    ll cost2 = (n/g)*(c1*_m1+c2*_m2) +  t2*(c1*n2-c2*n1)/g;

    if(cost1<cost2) t = t1;
    else t = t2;
    ll k1,k2;
    k1 = (_m1*n+n2*t)/g;
    k2 = (_m2*n-n1*t)/g;

    printf("%lld %lld\n",k1,k2);

}





return 0;
}
