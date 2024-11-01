
#include                        <bits/stdc++.h>
#include                        <ext/pb_ds/assoc_container.hpp>
#define lb                      lower_bound
#define ub                      upper_bound
#define fe(x)                   (*(x.begin()))
#define le(x)                   (*(x.rbegin()))
#define pb                      push_back
#define load(node,n)            bool operator < (const node &n) const
#define fbo(x,id)               (*(x.find_by_order(id)))
#define ook(y)                  order_of_key(y)
#define all(x)                  (x).begin(),(x).end()
#define si(a)                   scanf("%d",&a)
#define sii(a,b)                scanf("%d %d",&a,&b)
#define siii(a,b,c)             scanf("%d %d %d",&a,&b,&c)
#define sl(a)                   scanf("%lld",&a)
#define sll(a,b)                scanf("%lld %lld",&a,&b)
#define slll(a,b,c)             scanf("%lld %lld %lld",&a,&b,&c)
#define rep(i,a,b)              for(ll i = a; i<=b;  i++)
#define un(x)                   x.erase(unique(all(x)), x.end())
#define TT                      long long TC;  scanf("%lld",&TC);  while(TC--)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
#define SZ(x)                   (int)x.size()
#define ff                      first
#define ss                      second
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;

#define mx 100005

const ll P = 1e9+7;

ll fct[mx+2] = {1},inv[mx+2],pwr[mx+2] = {1};

ll bigmod(ll n,ll p,ll m){
    if(p==0)    return 1;
    if(p==1)    return n%m;
    ll x = bigmod(n,p/2,m)%m;
    if(p%2==0)  return (x*x)%m;
    return (((x*x)%m)*(n%m))%m;
}

ll ncr(ll n,ll r){
    if(n<r) return 0;
    return ( ((fct[n]*inv[r])%P)*inv[n-r])%P;
}

ll ar[mx][33];

main(){
//read;

for(ll i = 1; i<=mx; i++){
    fct[i] = (fct[i-1]*i)%P;
    pwr[i] = (2ll*pwr[i-1])%P;
}

inv[mx] = bigmod(fct[mx],P-2,P);

for(ll i = mx-1; i>=0; i--)
    inv[i] = ((i+1)*inv[i+1])%P;

ll n,q;
sll(n,q);

for(ll i = 1; i<=n; i++){
    ll x;
    sl(x);
    for(ll j = 0; j<=31; j++){
        if(x&(1ll<<j))  ar[i][j] = 1;
        ar[i][j]+=ar[i-1][j];
    }
}

while(q--){
    ll l,r;
    sll(l,r);
    ll ans = 0;
    for(ll i = 0; i<=31; i++){
        ll cnt = ar[r][i] - ar[l-1][i];
        if(cnt==0)  continue;
        ll p = 1ll<<i;
        p%=P;
        ll w = pwr[r - l];
        w = (w*p)%P;
        ans = (ans + w)%P;
    }
    printf("%lld\n",ans);
}

return 0;
}


