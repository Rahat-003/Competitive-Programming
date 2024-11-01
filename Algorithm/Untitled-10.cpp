#include                        "bits/stdc++.h"
// #include                        "ext/pb_ds/assoc_container.hpp"
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
// #define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
#define assign(v,n,x)           v.clear(); for(int I = 0; I<n; I++)    v.pb(x);
#define SZ(x)                   (int)x.size()
#define ff                      first
#define ss                      second
#define FF                      fflush(stdout);
#define infi                    0x3f3f3f3f
#define infl                    0x3f3f3f3f3f3f3f3f
#define ms(AR,x)                memset(AR,x,sizeof AR);
#define case                    printf("Case %lld: ",tc);
// using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;

#define mx 100005
const int MX = (1<<20) + 100;

int n,m,k,sq;

int block(int x){
    --x;
    return x/sq;
}



main(){
//read;

    cin >> n >> m >> k;
    sq = sqrt(n);
    int ar[n+5];

    for(int i = 1; i<=n; i++){
        si(ar[i]);
    }

    ll soln[mx];
    ms(soln,0);

    int ara[MX];
    ms(ara,0);

    vector<int> query[mx];

    for(int i = 1; i<=m; i++){
        int l,r;
        sii( l,r );
        if( block(l) == block(r) || true ){
            vector<int> tmp;
            tmp.pb(0);
            ara[0]++;
            int cur = 0;
            ll ans = 0;
            for(int j = l; j<=r; j++){
                cur^=ar[j];
                ans+=ara[cur^k];
                ara[cur]++;
                tmp.push_back(cur);
            }
            for(int j:tmp)  ara[j] = 0;
            soln[i] = ans;
        }
    }


    for(int i = 1; i<=m; i++){
        cout << "HI " << i << " "  << soln[i] << endl;
    }

    cout << endl;

    return 0;
}

