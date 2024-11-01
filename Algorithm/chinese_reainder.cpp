
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;



ll gcd(ll a,ll b,ll &x,ll &y){
    if(a==0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1,y1,g = gcd(b%a,a,x1,y1);
    y = x1;
    x = (g-b*y)/a;
    return g;
}


int main(){
ll sz;

while(1==scanf("%lld",&sz)){
    vector<ll> rem,num,pp,inv;

    ll product = 1,ans = 0;

    bool fl = true;
    for(ll i = 0; i<sz; i++){
        ll n;       scanf("%lld",&n);
        product*=n;
        num.push_back(n);
    }
    for(ll i = 0; i<sz; i++){
        ll n;
        scanf("%lld",&n);
        pp.push_back(product/num[i]);
        rem.push_back(n);
        ll N = pp[i], M = num[i];
        ll x,y, g = gcd( N,M,x,y );
        if(g!=1)    fl = false;
        ll mi = (x%M + M)%M;
        ans+= rem[i]*pp[i]*mi;
    }
    if(!fl){
        puts("Failed"); continue;
    }
    ans%=product;
    printf("%lld\n",ans);

}




return 0;
}
