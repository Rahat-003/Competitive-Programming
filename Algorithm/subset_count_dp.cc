/*******
*   Subset Count
*   https://atcoder.jp/contests/abc216/tasks/abc216_f
********/
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
#define TT                      long long TC;  scanf("%lld",&TC);  for(ll tc = 1; tc<=TC; tc++)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
#define assign(v,n,x)           v.clear(); for(int I = 0; I<n; I++)    v.pb(x);
#define SZ(x)                   (int)x.size()
#define ff                      first
#define ss                      second
#define FF                      fflush(stdout);
#define ms(AR,x)                memset(AR,x,sizeof AR);
#define case                    printf("Case %lld: ",tc);
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;

#define mx 5005

ll dp[mx][mx];

ll ar[mx];

const ll P = 998244353ll;

main(){
//read;

ll n;
sl(n);

vector<pll> v(n+5);

for(ll i = 1; i<=n; i++)    sl(v[i].ff);
for(ll i = 1; i<=n; i++)    sl(v[i].ss);

sort(v.begin() + 1, v.begin() + n + 1);

//for(ll i = 1; i<=n; i++)
//    cout<<v[i].ff<<" ";
//cout<<endl;

//cout<<endl;
//for(ll i = 1; i<=n; i++)
//    cout<<v[i].ss<<" ";
//cout<<endl<<endl;

//for(ll i = 0; i<mx; i++)    dp[i][0] = 1;

for(ll i = 1; i<=n; i++){
    ll x = v[i].ss;
    for(ll j = 0; j<mx; j++){
        dp[i][j] = dp[i-1][j];
    }
    for(ll j = 0; j<mx; j++){
        if(j+x>=mx) break;
        dp[i][j+x] = (dp[i-1][j] + dp[i-1][j+x] + 1)%P;
    }
}

for(int i = 0; i<mx; i++){
    for(int j = 0; j<mx; j++){
        dp[i][j] = (1+dp[i][j])%P;
    }
}

ll ans = 0;

for(int i = 1; i<=n; i++){
    if(v[i].ff<v[i].ss) continue;
    ans = (ans + dp[i-1][v[i].ff-v[i].ss])%P;
}

cout << ans << endl;

//cout << endl << endl;
//
//ll p = 20;
//
//for(ll i = 1; i<=p; i++)
//    printf("%3d ",i);
//
//cout << endl << endl;
//
//for(ll i = 1; i<=n; i++){
//    for(ll j = 1; j<=p; j++){
//        printf("%3d ",dp[i][j]);
//    }
//    cout << endl;
//}




return 0;
}



