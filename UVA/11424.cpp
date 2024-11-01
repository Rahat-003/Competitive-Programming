#include  <cstdio>
#include <numeric>

using namespace std;

typedef unsigned long long ll;
//#define mx (ll)2e5+2
#define mx (ll)1e7+2
ll phi[mx],tot[mx], ans[mx];

void totient(){
    iota(phi,phi+mx,0);

    for(ll i = 2; i<mx; i+=2)
        phi[i]/=2;

    for(ll i = 3; i<mx; i+=2){
        if(phi[i]==i){
            --phi[i];
            for(ll j = i*2; j<mx; j+=i)
                phi[j]-=phi[j]/i;
        }
    }
    phi[1] = 0;
}

void cal(){

    for(ll i = 2; i<mx; i++){
        ans[i] += ans[i-1] + phi[i];
        for(ll j = i+i; j<mx; j+=i){
            ll x = phi[j/i];
            ans[j]+= i*x;
        }
    }

}

int main(){
totient();
cal();
ll n;

/*
while(1==scanf("%llu",&n)){
    if(!n)  break;
    printf("%llu\n",ans[n]);
}
*/

return 0;
}
