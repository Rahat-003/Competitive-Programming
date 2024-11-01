//#include <numeric>
#include <cstdio>
#include <vector>
//#include <cmath>
#include <algorithm>
typedef long long ll;
#define mx 200003
using namespace std;

bool ar[mx];
ll phi[mx];
ll total[mx];


void sieve(){
//    prime.push_back(2);
    ar[0] = ar[1] =1;
    for(ll i =4; i<mx; i+=2)
        ar[i] = 1;

    for(ll i= 3; i*i<=mx; i+=2){
        if(!ar[i]){

            for(ll j = i*i; j<mx; j+=2*i)
                ar[j] = true;
        }
    }

//    for(ll i = 3; i<mx; i+=2)
//        if(!ar[i])  prime.push_back(i);
}

void totient(){
    for(ll i = 0 ; i<mx; i++){
        phi[i] = i;
        if(i%2==0)  phi[i]/=2;
    }
    for(ll i = 3; i<mx; i+=2){
        if(phi[i]==i){
        --phi[i];
        for(ll j = i+i; j<mx; j+=i)
            phi[j]-=phi[j]/i;
        }
    }
    phi[1] = 2;
    for(ll i = 1; i<mx; i++)
        total[i] = phi[i]+total[i-1];
}

void bal(ll n,ll &a,ll &b){
    b = 1;
    if(n==1){
        a = 0;  return;
    }
    if(n==2){
        a = 1;  return;
    }
    ll i = lower_bound(total,total+mx,n)-total;
        if(total[i]==n){
            b = i;
            a = i-1;
        return;
       }

        else if(total[i-1]<n && n<total[i]){
            b = i;
            a = 0;
            ll dif = n-total[i-1];
            if(!ar[i]){
                a = dif;
                return;
            }

            while(dif--){
                while(true){
                 a++;
                 if(__gcd(a,b)==1)   break;
                }
            }
        return;
        }

    return;
}

int main(){
//    freopen("tst.txt","r",stdin);
    sieve();
totient();

ll n;
while(1==scanf("%lld",&n)){
        if(!n)  break;
        ll a,b;
    bal(n,a,b);
//    printf("%lld\n",phi[n]);
    printf("%lld/%lld\n",a,b);
}

return 0;
}
