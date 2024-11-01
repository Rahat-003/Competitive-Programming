#include <cstdio>
#include <cmath>

typedef long long ll;

ll cnt(ll n, ll p){
    ll t = n/p - n/(p+1);
    return t*p;
}


ll f(ll n){
    if(n<0) return 0;
    if(n<2)    return n;

    ll one = n-n/2, ans = one;
    ll rt = sqrt(n);
    ll other = n/rt - 1;
    while(other>=2){
        ans+=cnt(n,other);
        other--;
    }

    for(ll i =1; i*i<=n; i++)
        ans+= n/i;
    return ans;
}


int main(){

//    freopen("tst.txt","r",stdin);

int t;
scanf("%d",&t);
while(t--){
    ll n;
    scanf("%lld",&n);
    ll ans = f(n);
    printf("%lld\n",ans);
}




return 0;
}
