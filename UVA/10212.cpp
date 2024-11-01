#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
typedef long long ll;
using namespace std;

int main(){
//    freopen("tst.txt","r",stdin);

ll n,r;
while(2==scanf("%lld %lld",&n,&r)){
    ll p = n-r+1;
    ll d5 = 0,d2 = 0, i5 = floor(p/5)*5;
    if(i5<p)    i5+=5;

    for(ll i = i5; i<=n; i+=5){
        ll x = i;
        while(x%5==0){
            d5++;
            x/=5;
        }
    }
    for(ll i = p; i<=n; i++){
        ll x = i;
        if(x%2==0){
            while(x%2==0){
                x/=2;
                d2++;
            }
            if(d2>d5)  break;
                i++;
        }
    }

    ll ans = 1;

//        printf("%lld ",i5);
    for(ll i = p; i<=n; i++){
        ll x = i;
        while(x%5==0 && d2>0){
        x/=5;
        d2--;
        }

        if(x%2==0){
            while(x%2==0 && d5>0){
                x/=2;
                d5--;
            }

            ans*=x;
            ans%=10;
        }
        else{
            ans*=x;
            ans%=10;
        }

    }

    printf("%lld\n",ans);


}




return 0;
}
