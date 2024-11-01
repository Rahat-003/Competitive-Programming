
#include <cstdio>
typedef long long ll;
#define mx 50000

bool ar[mx+3];
ll gcd(ll a, ll b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}

bool isPrime(ll a){

    if(a==2)    return true;

    if(a%2==0)  return false;

    for(ll i = 3; i*i<=a; i+=2)
        if(a%i==0)  return false;

    return true;
}


bool check(ll a,ll b){

    if(b==1)  return true;
    if(!b)  return false;

    if(b>a && isPrime(b))   return false;


    for(ll i = a; i>=2; i--){

//        if(b==1)    return true;

        ll g = gcd(b,i);

        if(g>1){
            b/=g;

            if(b<i)    return true;

            if(isPrime(b))
                return false;
        }

    }

    return false;
}

int main(){

//freopen("tst.txt","r",stdin);

ll p,q;
//sieve();

while(scanf("%lld %lld",&p,&q)==2){

    if(p>=q && p && q){
        printf("%lld divides %lld!\n",q,p);
        continue;
    }

    if(check(p,q)){
        printf("%lld divides %lld!\n",q,p);
    }
    else
        printf("%lld does not divide %lld!\n",q,p);

}


return 0;
}
