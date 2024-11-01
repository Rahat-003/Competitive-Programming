/**

***************************************************************
*                                                             *
*       HLD                                                   *
*       add w to all edges in the path from x to y            *
*       query in the path from x to y                         *
*                                                             *
***************************************************************

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

#define mx 100003

const int MX = 2e9;

vector<pii> v[mx];

int sub[mx],ar[mx],pos[mx],id;

int head[mx],par[mx],lvl[mx];
pii heavy[mx];

int ara[mx];

void dfs(int u = 1,int a = 0){
    lvl[u] = lvl[a] + 1;
    sub[u] = 1;
    par[u] = a;
    int x = 0;
    for(auto i:v[u]){
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


struct node{
    int max_val,min_val,sum;
    node(){};
    node(int a,int b,int c){    max_val = a;    min_val = b;  sum = c; }
};

namespace segment_tree{
    int N;
    struct sample{
        vector<node> tr;  vector<int> lazy;

        /// build function

        void build(int n = 1,int l = 1,int r = N){
            int L = n<<1,R = L+1,m = l+r>>1;
            if(l==r){
                /// check here
                /// initial tree er edge er value build korar somoy update hobe
                /// segment tree ke dfs(), decompose() korar por call korte hobe
                tr[n] = node( ar[ara[l]],ar[ara[l]],ar[ara[l]] );
                return;
            }
            build(L,l,m);
            build(R,m+1,r);
            tr[n].sum = tr[L].sum + tr[R].sum;
            tr[n].max_val = max(tr[L].max_val,tr[R].max_val);
            tr[n].min_val = min(tr[L].min_val,tr[R].min_val);
        }

        sample(int SIZE){
            N = SIZE;
            tr = vector<node> (4*N+2,node(0,0,0));
            lazy = vector<int> (4*N+2,0);
            build();
        }

        void relax(int n,int l,int r){
            int L = n<<1,R = L+1,m = l+r>>1;
            if(lazy[n]==0)  return;
            tr[n].sum+=(r-l+1)*lazy[n];
            tr[n].max_val+=lazy[n];
            tr[n].min_val+=lazy[n];
            if(l!=r)    lazy[L]+=lazy[n],lazy[R]+=lazy[n];
            lazy[n] = 0;
        }
        void update(int ql,int qr,int x,int n = 1,int l = 1,int r = N){
            relax(n,l,r);
            int L = n<<1,R = L+1, m = l+r>>1;
            if(r<ql || qr<l)    return;
            if(ql<=l && r<=qr){
                lazy[n]+=x;
                relax(n,l,r);
                return;
            }
            update(ql,qr,x,L,l,m);
            update(ql,qr,x,R,m+1,r);
            tr[n].sum = tr[L].sum + tr[R].sum;
            tr[n].max_val = max(tr[L].max_val,tr[R].max_val);
            tr[n].min_val = min(tr[L].min_val,tr[R].min_val);
        }
        node query(int ql,int qr,int n = 1,int l = 1,int r = N){
            relax(n,l,r);
            int L = n<<1,R = L+1, m = l+r>>1;
            if(r<ql || qr<l)    return node(-MX,MX,0);
            if(ql<=l && r<=qr)  return tr[n];
            node a = query(ql,qr,L,l,m),b = query(ql,qr,R,m+1,r);
            return node(max(a.max_val,b.max_val),min(a.min_val,b.min_val),a.sum+b.sum);
        }
    };
}


main(){
//read;
//write;

int n;
si(n);

//map<pii,int> mp;

for(int i = 1; i<n; i++){
    int a,b,c;
    siii(a,b,c);
    if(a>b) swap(a,b);
//    mp[pii(a,b)] = c;
    v[a].pb(pii(b,c));
    v[b].pb(pii(a,c));
}

dfs();

decompose();

segment_tree :: sample X(n);

int q;
cin>>q;

while(q--){
    int fl,x,y;
    siii(fl,x,y);

    if(fl==1){
        /// add w to all edges in the path from x to y
        int w;
        si(w);

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
    else{
        ///query
        node ans = node(-MX,MX,0);

        for( ; head[x]!=head[y] ; y = par[head[y]] ){
            if(lvl[head[x]]>lvl[head[y]])   swap(x,y);
            node p = X.query( pos[head[y]], pos[y] );
            ans = node(max(ans.max_val,p.max_val),min(ans.min_val,p.min_val),ans.sum+p.sum);
        }
        if(lvl[x]>lvl[y])   swap(x,y);

        if(x!=y){
            node p = X.query(pos[x]+1,pos[y]);
            ans = node( max(ans.max_val,p.max_val),min(ans.min_val,p.min_val) , ans.sum+p.sum );
        }
        cout<<"sum "<<ans.sum<<" max_val "<<ans.max_val<<" min_val "<<ans.min_val<<endl;

    }
}




return 0;
}


