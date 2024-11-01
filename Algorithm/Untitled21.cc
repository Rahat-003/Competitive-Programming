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

#define mx 100005

vector<int> v[mx],ara[mx];

int ar[mx],sub[mx],vis[mx];

int id[mx];
int N;

int tr[4*mx],lazy[4*mx];

void relax(int n,int l,int r){
    int L = 2*n,R = L+1,m = l+r>>1;
    if(lazy[n]==0)  return;
    if(l!=r){
        lazy[L] = lazy[R] = lazy[n];
    }
}

void update(int ql,int qr,int val,int n = 1,int l = 1,int r = N){
    int L = 2*n,R = L + 1,m = l+r>>1;
    relax(n,l,r);
    if(r<ql || qr<l)    return;
    if(ql<=l && r<=qr){
        lazy[n] = val;
//        cout<<"QQ "<<l<<" "<<r<<" node "<<n<<" "<<lazy[n]<<endl;
        relax(n,l,r);
        return;
    }
    update(ql,qr,val,L,l,m);
    update(ql,qr,val,R,m+1,r);
//    tr[n] = tr[L] + tr[R];
}

int query(int ql,int qr,int n = 1,int l = 1,int r = N){
    relax(n,l,r);
    int L = 2*n,R = L + 1,m = l+r>>1;
    if(r<ql || qr<l)    return 0;
    if(ql<=l && r<=qr){
        if(lazy[n]>0) return r - l + 1;
        return 0;
    }
    return query(ql,qr,L,l,m) + query(ql,qr,R,m+1,r);
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
} X(mx);



int cnt;

void dfs(int u,int a){
    id[u] = ++cnt;
    sub[u] = 1;
    for(int i:v[u]){
        if(i==a)    continue;
        dfs(i,u);
        sub[u]+=sub[i];
    }
}

void dfs2(int u,int a){
    for(int i:ara[u]){
        int l = id[i],r = l + sub[i] - 1;
//        cout<<endl;
        int val = sub[i] - query(l,r);
//        cout<<"HI cur "<<u<<" i "<<i<<" val "<<val<<endl;
        X.update(id[u],id[u] + sub[u] - 1,val);
        update(l,r,1);
    }

    for(int i:v[u]){
        if(i==a)    continue;
        dfs2(i,u);
    }

    for(int i:ara[u]){
        update(id[i],id[i]+sub[i]-1,-1);
    }

}


main(){
//read;

int n,m;
sii(n,m);

N = n;

for(int i = 1; i<n; i++){
    int a,b;
    sii(a,b);
    v[a].pb(b);
    v[b].pb(a);
}


for(int i = 0; i<m; i++){
    int a,b;
    sii(a,b);
    ara[a].pb(a);
    ara[a].pb(b);
    ara[b].pb(a);
    ara[b].pb(b);
}

for(int i = 1; i<mx; i++){
    sort(all(ara[i]));
    un(ara[i]);
}

dfs(1,0);

dfs2(1,0);

//cout<<endl;

for(int i = 1; i<=n; i++){
    int x = X.query(id[i],id[i]);
    x = max(0,x-1);
    printf("%d ",x);
}





return 0;
}

