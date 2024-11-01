
#include <cstdio>
#define ll unsigned long long
int main(){


ll n;

while(1==scanf("%llu",&n)){
        if(!n)  break;
    ll x = n*10/9,y = x-1;

    if(n%9==0){
        printf("%llu %llu\n",y,x);
    }
    else printf("%llu\n",x);
}







return 0;
}
