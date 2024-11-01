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
#define case                    printf("Case %lld: ",tc);
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;

#define mx 50002

ll up[mx][502],down[mx][502];

vector<int> v[mx];

int k;

void dfs(int u,int a){
    down[u][0] = 1;

    for(int i:v[u]){
        if(i==a)    continue;
        dfs(i,u);
        for(int x:v[u]){
            if(x==a)    continue;
            for(int j = 0; j<=k; j++){
                down[u][j+1]+=down[x][j];
            }
        }
    }

//    for(int i:v[u]){
//        if(i==a)    continue;
//        for(int j = 0; j<=k; j++){
//            down[u][j+1]+=down[i][j];
//        }
//    }

}


void dfs2(int u,int a){

    for(int i:v[u]){
        if(i==a)    continue;

        for(int j = 1; j<=k; j++){
            ll w = 0;
            if(j>=2)    w = down[i][j-2];
            up[i][j] = up[u][j-1] + down[u][j-1] - w;
        }

        dfs2(i,u);
    }
}


main(){
//read;


int n;
sii(n,k);

for(int i = 1; i<n; i++){
    int a,b;
    sii(a,b);
    v[a].pb(b);
    v[b].pb(a);
}

dfs(1,0);

dfs2(1,0);

ll ans = 0;

for(int i = 1; i<=n; i++){
    ans+=up[i][k] + down[i][k];
}

cout<<ans/2;


    return 0;
}

