/**
    https://www.spoj.com/problems/HMLIS/
**/

#include                        <cstdio>
#include                        <algorithm>
#include                        <vector>
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
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;

#define mx 100002

pii tr[4*mx];

int ar[mx];

const int P = 1000000007;

int N;

void update(int ql,int qr,int val,int cnt,int n = 1,int l = 1,int r = N){
    int L = 2*n,R = L+1,m = l+r>>1;
    if(r<ql || qr<l)   return;
    if(ql<=l && r<=qr){
        tr[n] = pii(val,cnt);
        tr[n].ss%=P;
        return;
    }
    update(ql,qr,val,cnt,L,l,m);
    update(ql,qr,val,cnt,R,m+1,r);
    tr[n].ff = max(tr[L].ff,tr[R].ff);
    if(tr[L].ff==tr[R].ff)  tr[n].ss = tr[L].ss + tr[R].ss;
    else tr[n].ss = (tr[L].ff > tr[R].ff) ? tr[L].ss : tr[R].ss;
    tr[n].ss%=P;
}

pii query(int ql,int qr,int n = 1,int l = 1,int r = N){
    int L = 2*n,R = L + 1,m = l+r>>1;
    if(r<ql || qr<l || ql>qr)    return pii(0,0);
    if(ql<=l && r<=qr)  return tr[n];
    pii a = query(ql,qr,L,l,m),b = query(ql,qr,R,m+1,r),c;
    c.ff = max(a.ff,b.ff);
    if(a.ff==b.ff)  c.ss = a.ss + b.ss;
    else c.ss = (a.ff > b.ff) ? a.ss : b.ss;
    c.ss%=P;
    return c;
}

pii ara[mx];

main(){
//read;

int n;
si(n);
N = n;

vector<int> v;

for(int i = 1; i<=n; i++)   si(ar[i]),v.pb(ar[i]);

sort(all(v));
un(v);

for(int i = 1; i<=n; i++){
    ar[i] = ub(all(v),ar[i]) - v.begin();
}

for(int i = 1; i<=n; i++){
    int x = ar[i];
    pii u = query(1,x-1);
    pii cur;// = query(x,x);
    cur = ara[x];
    pii val;
    if(u.ff==0) u.ss = 1;
    val.ff = max(u.ff+1,cur.ff);
    if(u.ff+1==cur.ff)    val.ss = (u.ss+cur.ss)%P;
    else{
        val.ss = ( u.ff + 1 > cur.ff ) ? u.ss : cur.ss;
    }
    update(x,x,val.ff,val.ss%P);
    ara[x] = max(ara[x],val);
}

printf("%d %d\n",tr[1].ff,tr[1].ss);


return 0;
}



