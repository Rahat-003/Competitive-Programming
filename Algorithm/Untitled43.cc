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
typedef                         pair<pii,int> ppp;


#define mx 200005

struct BIT{
    int SIZE;
    vector<int> tr1,tr2;
    BIT(int N){
        SIZE = N;
        tr1 = vector<int> (SIZE+5,0);    tr2 = tr1;
    }

    void add(vector<int> &ar,int i,int val){
        for(;i<=SIZE;i+=i&-i)  ar[i]+=val;
    }
    void update(int l,int r,int val){
        add(tr1,l,val);       add(tr1,r+1,-val);
        add(tr2,l,(l-1)*val); add(tr2,r+1,-r*val);
    }
    int prefix_sum(vector<int> &ar,int i){
        int tot = 0;    for(;i;i-=i&-i) tot+=ar[i];
        return tot;
    }
    int sum(int i){ return prefix_sum(tr1,i)*i - prefix_sum(tr2,i); }
    int query(int l,int r){
        if(l<=0)     l = 1;
        if(r<l)        return 0;
        return sum(r)-sum(l-1);
    }
};

int MX = 1e9;

struct node{
    int max_val,min_val,sum,fid;
    node(){};
    node(int a,int b,int c,int d){
        max_val = a;
        min_val = b;
        sum = c;
        fid = d;
    }
};

namespace segment_tree{
    int N;
    struct sample{
        vector<node> tr;  vector<int> lazy;

        void build(int n = 1,int l = 1,int r = N){
            if(l==r){
                tr[n] = node(0,0,0,l);
                return;
            }
            int L = 2*n,R = L+1,m = l+r>>1;
            build(L,l,m);
            build(R,m+1,R);
            tr[n].sum = tr[L].sum + tr[R].sum;
            tr[n].max_val = max(tr[L].max_val,tr[R].max_val);
            tr[n].min_val = min(tr[L].min_val,tr[R].min_val);
            if(tr[n].min_val==tr[L].min_val)    tr[n].fid = tr[L].fid;
            else tr[n].fid = tr[R].fid;
        }

        sample(int SIZE){
            N = SIZE;
            tr = vector<node> (4*N+2,node(0,0,0,0));
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
            if(tr[n].min_val==tr[L].min_val)    tr[n].fid = tr[L].fid;
            else tr[n].fid = tr[R].fid;
        }
        node query(int ql,int qr,int n = 1,int l = 1,int r = N){
            relax(n,l,r);
            int id,L = n<<1,R = L+1, m = l+r>>1;
            if(r<ql || qr<l)    return node(-MX,MX,0,0);
            if(ql<=l && r<=qr)  return tr[n];
            node a = query(ql,qr,L,l,m),b = query(ql,qr,R,m+1,r);
            if(min(a.min_val,b.min_val)==a.min_val) id = a.fid;
            else id = b.fid;
            return node(max(a.max_val,b.max_val),min(a.min_val,b.min_val),a.sum+b.sum,id);
        }
    };
}

main(){
//read;


set(pii) L,R;//,cur;
set(int) vis;

int n,m;
sii(n,m);

for(int i = 1; i<=n; i++)   vis.insert(i);

deque<ppp> v;

for(int i = 0; i<m; i++){
    int a,b,c;
    siii(a,b,c);
    v.pb(ppp(pii(a,b),c));
}

sort(all(v));
v.push_front(ppp({0,0},0));


int id = 0;

segment_tree :: sample X(mx);

/*
for(int i = 1; i<=m; i++){
    pii u = v[i].ff;
    int x = v[i].ss;

    while( id+1<=m && ( SZ(L)==0 || max( le(L).ff, v[id+1].ff.ff ) <= min(fe(R).ff,v[id+1].ff.ss) ) ) {
        id++;
        L.insert(pii(v[id].ff.ff,id));
        R.insert(pii(v[id].ff.ss,id));
        X.update(id,id,v[id].ss);
    }

    node qq = X.query(i,i);

    if(qq.min_val>0 && qq.min_val<mx ){
        node cur;
        int val;
        while(1){
            cur = X.query(i,id);
            val = cur.min_val;
            if(val>0)   break;
            int idx = cur.fid;
            L.erase(pii(v[idx].ff.ff,id));
            R.erase(pii(v[idx].ff.ss,id));
            X.update( idx, idx, val + MX );
        }

        int l = le(L).ff,r = fe(R).ff;
        if(val>=r-l+1){
            continue;
        }
    }



    L.erase({u.ff,i});
    R.erase({u.ss,i});
//    cur.erase(pii(x,i));
}

*/


return 0;
}

