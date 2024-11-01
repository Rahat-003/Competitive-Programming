#include <cstdio>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define mx 100003
const ll P = 1000007;

ll ar[mx];
vector<ll> a;

int main(){
int t,tc = 0;
scanf("%d",&t);
while(t--){
    ll k,c,n,p;
    scanf("%lld%lld%lld%lld",&k,&c,&n,&p);
    a = vector<ll> (n);
    memset(ar,0,sizeof ar);
    a[0] = p;

    for(ll i = 1; i<n; i++) a[i] = ( (k*a[i-1])%P + c)%P;
    sort(a.begin(),a.end());

    for(ll i = n-1; i>=1; i--)  ar[i]=a[i]+ar[i+1];
    ll ans = 0;

    for(ll i = 0; i<n-1; i++)
        ans+=ar[i+1] - a[i]*(n-1-i);
    case;
    printf("%lld\n",ans);
}

return 0;
}

