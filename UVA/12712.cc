#include <bits/stdc++.h>
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define mx 10002
const ll P = 10000000000007ll;

//ll fct[mx];

/*
100 1 10000
1075683498104
*/

main(){
//read;
int t;
scanf("%d",&t);
for(int T = 1; T<=t; T++){
    ll ans = 0;
    ll a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    ll p = 1,q;

    for(ll i = a*a, j = 0; j<b; j++, i-- ){
        p = (p*i)%P;
        q = i;
    }
    ans = p;
    for(ll i = b+1, k = q-1; i<=c; i++,k--){
        p = (p*k)%P;
        ans = (ans+p)%P;

    }
    printf("Case %d: ",T);
    printf("%lld\n",ans);
}

return 0;
}
