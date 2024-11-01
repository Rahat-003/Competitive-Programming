/***
    Given an array and queries. 1<=n,q<=3e5
    For each query given l,r,x
    Find largest number in range l to r which is smaller or equal to x.
    If there is no number print 0
**/

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


#define mx 300001

vector<int> tr[4*mx];

int ar[mx],N;


void build(int n = 1,int l = 1,int r = N){
    int L = 2*n,R = L+1,m = l+r>>1;
    if(l==r){
        tr[n].pb(ar[l]);
        return;
    }
    build(L,l,m);
    build(R,m+1,r);
    for(int i:tr[L])    tr[n].pb(i);
    for(int i:tr[R])    tr[n].pb(i);
    sort(all(tr[n]));
}

int query(int ql,int qr,int x,int n = 1,int l = 1,int r = N){
    int L = 2*n,R = L+1,m = l+r>>1;
    if(r<ql || qr<l)    return 0;
    if(ql<=l && r<=qr){
        int id = lb(all(tr[n]),x+1) - tr[n].begin();
        id--;
        if(id==-1)  return 0;
        return tr[n][id];
    }
    return max(query(ql,qr,x,L,l,m),query(ql,qr,x,R,m+1,r));
}


main(){
//read;


int n,q;
sii(n,q);
N = n;
for(int i = 1; i<=n; i++)   si(ar[i]);

build();

for(int i = 0; i<q; i++){
    int l,r,k;
    siii(l,r,k);
    l++,r++;
    printf("%d\n",query(l,r,k));
}


return 0;
}


