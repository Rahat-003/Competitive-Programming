/**
*   CF 600E - Lomsat gelral
*   sqrt decomposition - no update
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

#define mx 100003

vector<int> v[mx];

int sub[mx],id[mx],c[mx],nc[mx],freq[mx],tfreq[mx];
int cnt,n,len;
ll sum[mx],tsum[mx];
ll ans[mx];

deque<pii> dq[mx];

void dfs(int u,int a){
    cnt++;
    id[u] = cnt;
    nc[cnt] = c[u];
    sub[u] = 1;
    for(int i:v[u]){
        if(i==a)    continue;
        dfs(i,u);
        sub[u]+=sub[i];
    }
}


int block(int x){
    x--;
    return x/len;
}


main(){
//read;

si(n);
len = sqrt(n);

for(int i = 1; i<=n; i++){
    si(c[i]);
}

for(int i = 1; i<n; i++){
    int a,b;
    sii(a,b);
    v[a].pb(b);
    v[b].pb(a);
}


dfs(1,0);

for(int i = 1; i<=n; i++){
    int l = id[i],r = l+sub[i]-1;
    if(block(l)==block(r)){
        vector<int> tf,ts;
        ll a = 0;
        for(int j = l; j<=r; j++){
            int x = nc[j];
            freq[x]++;
            tf.pb(x);
            ll q = freq[x];
            a = max(a,q);
            sum[q]+=x;
            ts.pb(q);
        }
        ans[i] = sum[a];
        for(ll j:tf)
            freq[j] = 0;
        for(ll j:ts)
            sum[j] = 0;
    }
    else{
        dq[r].pb(pii(l,i));
    }
}

for(int i = 0; i<=n; i++){
    sort(all(dq[i]));
}


for(ll i = 1; i<=n; i+=len){
    memset(sum,0,sizeof sum);
    memset(freq,0,sizeof freq);
    int a = 0;
    for(ll k = i; k<=n; k++){
        ll x = nc[k];
        freq[x]++;
        sum[freq[x]]+=x;
        a = max(a,freq[x]);

        while(SZ(dq[k]) && dq[k][0].ff<=i){
            vector<int> tf,ts;
            int b = a;
            for(int j = i-1; j>=dq[k][0].ff; j--){
                ll y = nc[j];
                tfreq[y]++;
                b = max(b,tfreq[y] + freq[y] );
                tsum[ tfreq[y] + freq[y] ]+=y;
                tf.pb(y);
                ts.pb(tfreq[y] + freq[y]);
            }

            ans[dq[k][0].ss] = sum[b] + tsum[b];
            dq[k].pop_front();
            for(int j:tf)   tfreq[j] = 0;
            for(int j:ts)   tsum[j] = 0;
        }

    }
}

for(ll i = 1; i<=n; i++){
    printf("%lld ",ans[i]);
}


return 0;
}



