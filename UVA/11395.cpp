
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
//    freopen("tst.txt","r",stdin);
ll n;
while(1==scanf("%lld",&n)){
        if(n==0)    break;
        ll ans = n-(ll)sqrt(n)-(ll)sqrt(n/2);

    printf("%lld\n",ans);
}






return 0;
}
