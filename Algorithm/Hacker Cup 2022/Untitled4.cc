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
#define infi                    0x3f3f3f3f
#define infl                    0x3f3f3f3f3f3f3f3f
#define ms(AR,x)                memset(AR,x,sizeof AR);
#define case                    printf("Case #%lld: ",tc);
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;


ll n;

ll mod = 7 + 1e9;

ll fn( vector<ll> &v, vector<ll> &pref, vector<ll> &pref_sq, ll x ){
    ll id = ub(all(v),x) - v.begin();
    ll tot = 0;
    if(id){
        tot = (((((id*x)%mod)*x)%mod + pref_sq[id-1])%mod - (((2ll*x)%mod)*pref[id-1])%mod )%mod;
        tot = (tot+mod)%mod;
    }
    if(id!=n){
        ll ache = n - id,w = 0;
        ll p1 = 0,p2 = 0;
        if(id){
            p1 = pref[id-1];
            p2 = pref_sq[id-1];
        }

        ll bc = (pref[n-1] - p1 + mod)%mod;
        bc+=mod;
        bc%=mod;

        ll bc_sq = (pref_sq[n-1] - p2 + mod)%mod;
        bc_sq+=mod;
        bc_sq%=mod;

        w = ( (((ache*x)%mod)*x)%mod - (2ll*x*bc)%mod + bc_sq)%mod;

        tot+=w;
        tot%=mod;
        tot = (tot + mod)%mod;
    }
    tot%=mod;
    return (tot+mod)%mod;
}


main(){
read;
write;

    TT{
        sl(n);

        vector<ll> v[2], pref[2], pref2[2];

        for(ll i = 0; i<2; i++){
            v[i] = vector<ll> (n);
            pref[i] = vector<ll> (n);
            pref2[i] = vector<ll> (n);
        }

        for(int i = 0; i<n; i++){
            for(ll j = 0; j<2; j++){
                sl(v[j][i]);
            }
        }

        sort(all(v[0]));
        sort(all(v[1]));

        for(ll i = 0; i<n; i++){
            for(ll j = 0; j<2; j++){
                pref[j][i] = v[j][i];
                pref2[j][i] = v[j][i]*v[j][i];
                pref2[j][i]%=mod;
                if(i){
                    pref[j][i]+=pref[j][i-1];
                    pref2[j][i]+=pref2[j][i-1];

                    pref[j][i]%=mod;
                    pref2[j][i]%=mod;
                }
            }
        }


        ll q;
        sl(q);

        ll tot = 0;

        while(q--){
            ll x,y;
            sll(x,y);
            ll a = fn(v[0],pref[0],pref2[0],x);
            ll b = fn(v[1],pref[1],pref2[1],y);
            ll ans = (a+b)%mod;
            tot+=ans;
            tot%=mod;
        }
        case;
        printf("%lld\n",tot);


    }




    return 0;
}

