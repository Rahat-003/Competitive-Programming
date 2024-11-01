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
#define read                    freopen("chainblock_input.txt","r",stdin)
#define write                   freopen("output2.txt","w",stdout)
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

#define mx 800006

const int MX = 2e9;

vector<pii> v[mx];
vector<int> data[mx];
int sub[mx],ar[mx],pos[mx],id;

int head[mx],par[mx],lvl[mx];
pii heavy[mx];
int ara[mx];

void clr(int n){
    id = 0;
    for(int i = 0; i<=n; i++){
        v[i].clear();
        data[i].clear();
        sub[i] = 0;
        ar[i] = 0;
        pos[i] = 0;
        head[i] = 0;
        par[i] = 0;
        lvl[i] = 0;
        heavy[i] = pii(0,0);
        ara[i] = 0;
    }

}

void dfs(int u = 1,int a = 0){
    lvl[u] = lvl[a] + 1;
    sub[u] = 1;
    par[u] = a;
    int x = 0;
    for(pii i:v[u]){
        if(i.ff==a)    continue;
        dfs(i.ff,u);
        sub[u]+=sub[i.ff];
        if(x<sub[i.ff]){
            x = sub[i.ff];
            heavy[u] = i;
        }
    }

}


void decompose(int u = 1,int h = 1,int c = 0){
    pos[u] = ++id;
    ara[id] = u;
    head[u] = h;
    ar[u] = c;
    if(heavy[u].ff){
        decompose( heavy[u].ff, h , heavy[u].ss );
    }
    for(auto i:v[u]){
        if(i.ff==par[u] || i.ff==heavy[u].ff) continue;
        decompose(i.ff,i.ff,i.ss);
    }
}



struct BIT{
    int SIZE;
    vector<int> TREE1,TREE2;
    BIT(int N){
        SIZE = N;
        TREE1 = vector<int> (SIZE+5,0);    TREE2 = TREE1;
    }

    void add(vector<int> &ar,int i,int val){
        for(;i<=SIZE;i+=i&-i)  ar[i]+=val;
    }
    void update(int l,int r,int val){
        add(TREE1,l,val);       add(TREE1,r+1,-val);
        add(TREE2,l,(l-1)*val); add(TREE2,r+1,-r*val);
    }
    int prefix_sum(vector<int> &ar,int i){
        int tot = 0;    for(;i;i-=i&-i) tot+=ar[i];
        return tot;
    }
    int sum(int i){ return prefix_sum(TREE1,i)*i - prefix_sum(TREE2,i); }
    int query(int l,int r){
        if(l<=0)     l = 1;
        if(r<l)        return 0;
        return sum(r)-sum(l-1);
    }
};



main(){
read;
write;

TT{
    int n,tot = 0;
    si(n);
    clr(n);
    vector<pii> edge;

    for(int i = 1; i<n; i++){
        int a,b,c = 0;
        sii(a,b);
    //    siii(a,b,c);
        if(a>b) swap(a,b);
    //    mp[pii(a,b)] = c;
        edge.pb(pii(a,b));
        v[a].pb(pii(b,c));
        v[b].pb(pii(a,c));
    }

    for(int i = 1; i<=n; i++){
        int x;
        si(x);
        data[x].pb(i);
    }

    dfs();
    decompose();
    BIT X(n+2);

    for(int i = 1; i<=n; i++){
        if(SZ(data[i])<=1)  continue;
        for(int j = 1; j<SZ(data[i]); j++){
            int x = data[i][0],y = data[i][j];
            int w = 1;
            if(x!=y){
                for( ; head[x]!=head[y] ; y = par[head[y]] ){
                    if(lvl[head[x]]>lvl[head[y]])   swap(x,y);
                    X.update( pos[head[y]], pos[y] , w );
                }

                if(lvl[x]>lvl[y])   swap(x,y);
                if(x!=y){
                    X.update(pos[x]+1,pos[y],w);
                }
            }
        }
    }

    for(auto i:edge){
        int ans = 0,x = i.ff,y = i.ss;
        for( ; head[x]!=head[y] ; y = par[head[y]] ){
            if(lvl[head[x]]>lvl[head[y]])   swap(x,y);
            int p = X.query( pos[head[y]], pos[y] );
            ans+=p;
            if(ans) goto qq;
        }
        if(lvl[x]>lvl[y])   swap(x,y);

        if(x!=y){
            int p = X.query(pos[x]+1,pos[y]);
            ans+=p;
        }
        qq:
        if(ans==0)  tot++;
    }
    case;
    printf("%d\n",tot);
}




return 0;
}




