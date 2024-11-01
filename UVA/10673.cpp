

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

int t;
scanf("%d",&t);
while(t--){
    ll x,k,c,d;
    scanf("%lld %lld",&x,&k);
    ll n1 = floor(x/(double)k);
    ll n2 = ceil(x/(double)k);

    ll g = gcd(n1,n2,c,d);
    ll t1,t2,t;
    t1 = ceil(-c*x/(double)n2);
    t2 = floor(d*x/(double)n1);
    ll cost1 = t1*(n2-n1)/g;
    ll cost2 = t2*(n2-n1)/g;
    if(cost1<cost2) t = t1;
    else t = t2;


    ll k1 = c*(x/g)+n2/g*t;
    ll k2 = d*(x/g)-n1/g*t;
    printf("%lld %lld\n",k1,k2);

}



return 0;
}
