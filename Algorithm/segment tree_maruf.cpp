

const ll MX = 1e16;

struct node{
    ll max_val,min_val,sum,max_id,min_id;
    node(){};
    node(ll a,ll b,ll c,ll d,ll e){
        max_val = a;
        min_val = b;
        sum = c;
        max_id = d;
        min_id = e;
    }
};

#define mx 200005

int ar[mx];

namespace segment_tree{
    ll N;
    struct sample{
        vector<node> tr;  vector<ll> lazy;

//        void build(ll n = 1,ll l = 1,ll r = N){
//            ll L = 2*n,R = L+1,m = l+r>>1;
//            if(l==r){
//                tr[n] = node(ar[l],ar[l],ar[l],l,l);
//                return;
//            }
//            build(L,l,m);
//            build(R,m+1,r);
//            tr[n].sum = tr[L].sum + tr[R].sum;
//            tr[n].max_val = max(tr[L].max_val,tr[R].max_val);
//            tr[n].min_val = min(tr[L].min_val,tr[R].min_val);
//            tr[n].min_id = ( tr[n].min_val==tr[L].min_val ? tr[L].min_id : tr[R].min_id) ;
//            tr[n].max_id = ( tr[n].max_val==tr[L].max_val ? tr[L].max_id : tr[R].max_id) ;
//        }

        sample(ll SIZE){
            N = SIZE;
            tr = vector<node> (4*N+2,node(0,0,0,0,0));
            lazy = vector<ll> (4*N+2,0);
//            build();
        }

        void relax(ll n,ll l,ll r){
            ll L = n<<1,R = L+1,m = l+r>>1;
            if(lazy[n]==0)  return;
            tr[n].sum+=(r-l+1)*lazy[n];
            tr[n].max_val+=lazy[n];
            tr[n].min_val+=lazy[n];
            if(l!=r)    lazy[L]+=lazy[n],lazy[R]+=lazy[n];
            lazy[n] = 0;
        }
        void update(ll ql,ll qr,ll x,ll n = 1,ll l = 1,ll r = N){
            relax(n,l,r);
            ll L = n<<1,R = L+1, m = l+r>>1;
            if(r<ql || qr<l)    return;
            if(ql<=l && r<=qr){
                lazy[n] = x;
                relax(n,l,r);
                return;
            }
            update(ql,qr,x,L,l,m);
            update(ql,qr,x,R,m+1,r);
            tr[n].sum = tr[L].sum + tr[R].sum;
            tr[n].max_val = max(tr[L].max_val,tr[R].max_val);
            tr[n].min_val = min(tr[L].min_val,tr[R].min_val);
            tr[n].min_id = ( tr[n].min_val==tr[L].min_val ? tr[L].min_id : tr[R].min_id) ;
            tr[n].max_id = ( tr[n].max_val==tr[L].max_val ? tr[L].max_id : tr[R].max_id) ;
        }
        node query(ll ql,ll qr,ll n = 1,ll l = 1,ll r = N){
            relax(n,l,r);
            ll L = n<<1,R = L+1, m = l+r>>1;
            if(r<ql || qr<l)    return node(-MX,MX,0,MX,MX);
            if(ql<=l && r<=qr)  return tr[n];
            node a = query(ql,qr,L,l,m),b = query(ql,qr,R,m+1,r);
            ll p = min(a.min_val,b.min_val)==a.min_val? a.min_id : b.min_id;
            ll q = max(a.max_val,b.max_val)==a.max_val? a.max_id : b.max_id;
            return node(max(a.max_val,b.max_val),min(a.min_val,b.min_val),a.sum+b.sum,q,p);
        }
    };
}
