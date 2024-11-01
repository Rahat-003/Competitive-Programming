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
#define case                    printf("Case #%lld: ",tc);
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;

#define mx 102

vector<int> v[mx];

ll ar[mx],ara[mx];

void dfs(int u,int a){
    ll x = 0;
    for(int i:v[u]){
        if(i==a)    continue;
        dfs(i,u);
        x = max(x,ara[i]);
    }
    ara[u] = ar[u] + x;
}



main(){
//read;
//write;

TT{
    ll n;
    sl(n);
    ms(ara,0);
    for(ll i = 1; i<=n; i++){
        sl(ar[i]);
        v[i].clear();
    }

    for(int i = 1; i<n; i++){
        int a,b;
        sii(a,b);
        v[a].pb(b);
        v[b].pb(a);
    }

    dfs(1,0);

    vector<ll> xx = {0,0};

    for(int i:v[1]){
        xx.pb(ara[i]);
    }
    sort(all(xx));
    reverse(all(xx));
    ll ans = ar[1] + xx[0] + xx[1];
    case;
    cout<<ans<<endl;
}






return 0;
}

