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

#define mx 100005

vector<ll> v;


ll n,k;

bool check(ll m){
    ll tot = 0;
    for(ll i = 0; i<n; i++){
        ll p = max(0ll, v[i] - m + 1);
        tot+=p;
    }
    return tot>=k;
}

ll sum(ll a,ll b){
    if(a>b) return 0;
    a--;
    a = a*(a+1)/2;
    b = b*(b+1)/2;
    return b - a;
}

main(){
//read;


sll(n,k);

for(ll i = 0; i<n; i++){
    ll x;
    sl(x);
    v.pb(x);
}

sort(all(v));

ll l = 1,r = 2e9,m,x = 0;


while(l<=r){
    m = l+r>>1;
    if(check(m))    l = m+1,x = m;
    else r = m-1;
}

set<pll> st;

ll cur = x+1 , ans = 0;

for(ll i = 0; i<n; i++){
    ll cnt = max(0ll, v[i] - cur + 1);

    if(k>=cnt){
        k-=cnt;
        st.insert(pll(v[i] - cnt,i));
        ans+=sum(cur,v[i]);
    }

}

while(k>0 && SZ(st)){
    pll u = le(st);
    k--;
    st.erase(u);
    if(u.ff>0)  ans+=u.ff;
    u.ff--;
    if(u.ff>0)  st.insert(u);
}


cout<<ans;

return 0;
}


