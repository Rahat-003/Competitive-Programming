#include                        <bits/stdc++.h>
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
#define SZ(x)                   (int)x.size()
#define ff                      first
#define ss                      second
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;


#define mx 100004

int L[mx],ar[mx],par[mx],tree[mx][21],n;

pii table[mx][22];

vector<pii> v[mx];



void dfs(int u,int a){
    L[u] = L[a]+1;
    par[u] = a;
    for(auto i:v[u]){
        if(i.first==a)  continue;
        table[i.ff][0] = {i.ss,i.ss};
        dfs(i.first,u);
    }
}

void build(){
    int sz = log2(n);
    for(int i = 1; i<=n; i++)   tree[i][0] = par[i];

    for(int i = 1; i<=sz; i++){
        for(int j = 1; j<=n; j++){
            if(tree[j][i-1]!=0){
                tree[j][i] = tree[tree[j][i-1]] [i-1];
                int x = table[j][i-1].ff, y = table[j][i-1].ss;
                int p = tree[j][i-1];
                int a = table[p][i-1].ff, b = table[p][i-1].ss;
                table[j][i] = {min(a,x),max(b,y)};
            }
        }
    }
}

pii LCA(int a,int b){
    if(L[a]>L[b])   swap(a,b);
    int sz = log2(n);

    int p = 1e9,q = -p;

    for(int i = sz; i>=0; i--){
        if(L[b]-(1<<i)>=L[a]){
            p = min(p,table[b][i].ff);
            q = max(q,table[b][i].ss);
            b = tree[b][i];
        }

    }

    for(int i = sz; i>=0; i--){
        if(tree[a][i]!=0 && tree[a][i]!=tree[b][i]){
            p = min({p,table[a][i].ff,table[b][i].ff});
            q = max({q,table[a][i].ss,table[b][i].ss});
            a = tree[a][i];
            b = tree[b][i];
        }
    }
    if(a==b)    return pii(p,q);
    p = min({p,table[a][0].ff,table[b][0].ff});
    q = max({q,table[a][0].ss,table[b][0].ss});
    return pii(p,q);
}





main(){
//read;

int tc = 0;

TT{
    si(n);
    for(int i = 1; i<=n; i++){
        v[i].clear();
        L[i] = 0;
        ar[i] = 0;
        par[i] = 0;
        for(int j = 0; j<21;  j++){
            tree[i][j] = 0;
            table[i][j] = pii(0,0);
        }
    }

    for(int i = 1; i<n; i++){
        int a,b,c;
        siii(a,b,c);
        v[a].pb(pii(b,c));
        v[b].pb(pii(a,c));
    }


    dfs(1,0);

    build();

    printf("Case %d:\n",++tc);

    int q;
    si(q);
    while(q--){
        int a,b;
        sii(a,b);
        pii x = LCA(a,b);
        printf("%d %d\n",x.ff,x.ss);
    }


}





return 0;
}

