/**
*   CF 617E
*   Sqrt decomposition_ no update
*
*/

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
#define assign(v,n,x)           v.clear(); for(int I = 0; I<n; I++)    v.pb(x);
#define SZ(x)                   (int)x.size()
#define ff                      first
#define ss                      second
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;


#define mx 1050000

deque<pii> v[100002];
ll ar[100002],ans[100002];

ll ara[mx],tmp[mx],n;

int block(int x){
    --x;
    int len = sqrt(n),p = x/len;
    return p+1;
}


main(){
//read;


ll m,z;

slll(n,m,z);

for(ll i = 1; i<=n; i++){
    sl(ar[i]);
}


for(ll i = 1; i<=m; i++){
    ll l,r;
    sll(l,r);
    if(block(l)==block(r)){
        vector<ll> waste;
        ll y = 0,w = 0;
        ara[0] = 1;
        for(ll j = l; j<=r; j++){
            ll x = ar[j];
            y^=x;
            w+=ara[y^z];
            ara[y]++;
            waste.pb(y);
        }
        for(ll j:waste) ara[j]--;
        ans[i] = w;
    }
    else{
        v[r].pb(pii(l,i));
    }
}

for(ll i = 0; i<=n; i++){
    sort(all(v[i]));
}

ll len = sqrtl(n);

for(ll i = 1; i<=n; i+=len){
    ll tot = 0,x = 0;
    memset(ara,0,sizeof ara);
    ara[0] = 1;
    for(ll k = i; k<=n; k++){
        x^=ar[k];
        tot+=ara[x^z];
        ara[x]++;
        while(SZ(v[k]) && v[k][0].ff<=i){
            vector<ll> waste;
            ll y = 0,p = tot;
            for(ll j = i-1; j>=v[k][0].ff; j--){
                y^=ar[j];
                p+=tmp[y^z];
                p+=ara[y^z];
                waste.pb(y);
                tmp[y]++;
            }
            ans[v[k][0].ss] = p;
            v[k].pop_front();
            for(ll j:waste) tmp[j]--;
        }
    }
}

for(ll i = 1; i<=m; i++)
    printf("%lld\n",ans[i]);


return 0;
}
