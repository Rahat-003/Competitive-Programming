
#include <memory.h>
#include <cstdio>

typedef long long ll;
#define mx (ll)1e6+3
bool ar[mx];

ll gcd(ll a,ll b){
    if(a==0)    return b;
    return gcd(b%a,a);
}

int main(){
ll n;

while(1==scanf("%lld",&n)){
    memset(ar,false,sizeof ar);
//    ll lmt = floor(sqrt(n));
    ll cnt = 0,cnt3 = 0;

    for(ll i  = 1; i*i<n; i++){
        for(ll j = i+1; j<n; j+=2){
            ll x = j*j-i*i;
            ll y = 2*i*j;
            ll z = i*i+j*j;

            if(z<=n && gcd(x,z)==1){
                cnt++;
                for(ll k = 1; k*z<=n ; k++){
                    if(!ar[x*k]){
                    ar[x*k] = true;
                        cnt3++;
                    }
                    if(!ar[y*k]){
                    ar[y*k] = true;
                        cnt3++;
                    }
                    if(!ar[z*k]){
                    ar[z*k] = true;
                        cnt3++;
                    }
                }

            }
        }
    }

    printf("%lld %lld\n",cnt,n-cnt3);

}




return 0;
}
