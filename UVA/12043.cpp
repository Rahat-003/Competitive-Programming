
#include <cstdio>
#include <vector>
using namespace std;

#define lim 320
typedef long long ll;
#define mx  (ll)1e5+3

vector<ll> prime;
bool ar[lim];
ll nDiv[mx],sigma[mx];

void sieve(){
    prime.push_back(2);
    for(ll i = 3; i*i<=lim; i+=2){
        if(!ar[i]){
            for(ll j = i*i; j<lim; j+=2*i)
                ar[j] = 1;
        }
    }
    for(ll i = 3; i<lim; i+=2)
        if(!ar[i])  prime.push_back(i);
}

void factor(ll n){
    ll x = n;
    ll num = 1,sum = 1;
    for(auto i:prime){
        if(i>n) break;
    if(n%i==0){
        ll p = i;
        ll t = 1;
        while(n%i==0){
            p*=i;
            t++;
            n/=i;
        }
        p-=1;
        sum*= (p/(i-1));
        num*=t;
        }
    }
    if(n>1){
        num*=2;
        ll f = (n*n-1)/(n-1);
        sum*=f;
    }
    nDiv[x] = num;
    sigma[x] = sum;
    return;
}

void make(){
    nDiv[1] = 1;
    sigma[1] = 1;
    for(ll i = 2; i<mx; i++){
        factor(i);
    }
}

int main(){
int t;
sieve();
make();

scanf("%d",&t);

while(t--){
    ll a,b,k;
    scanf("%lld %lld %lld",&a,&b,&k);
//    scanf("%lld",&a);
    ll p = k*(a/k);
    if(p<a) p+=k;
    ll x = 0,y = 0;
    for(ll i = p; i<=b; i+=k){
        x+=nDiv[i];
        y+=sigma[i];
    }

    printf("%lld %lld\n",x,y);

}




return 0;
}
