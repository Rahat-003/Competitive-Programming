
#include <cstdio>

typedef long long ll;

ll gcd(ll a,ll b, ll &x, ll &y){
    if(a==b){
        x = 0;
        y = 1;
        return a;
    }

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

ll a,b;

while(2==scanf("%lld %lld",&a,&b)){

    ll x,y;
    ll g = gcd(a,b,x,y);
    printf("%lld %lld %lld\n",x,y,g);
//    cout<<x<<" "<<y<<" "<<g<<endl;
}


return 0;
}
