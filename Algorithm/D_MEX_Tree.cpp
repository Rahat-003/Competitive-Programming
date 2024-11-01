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

#define mx 200005

int L[mx],ar[mx],par[mx],tr[mx][21],n;
vector<int> v[mx];
int sub[mx];
bool vis[mx];
ll ara[mx];

void clr(){
    for(int i = 0; i<=n+2; i++){
        v[i].clear();
        vis[i] = L[i] = ar[i] = par[i] = sub[i] = ara[i] = 0;
        for(int j = 0; j<21; j++)   tr[i][j] = 0;
    }
}

void dfs(int u,int a){
    L[u] = L[a]+1;
    par[u] = a;
    sub[u] = 1;
    for(int i:v[u]){
        if(i==a)  continue;
        dfs(i,u);
        sub[u]+=sub[i];
    }
}

void build(){
    int sz = log2(n);
    for(int i = 1; i<=n; i++)   tr[i][0] = par[i];
    for(int i = 1; i<=sz; i++){
        for(int j = 1; j<=n; j++){
            if(tr[j][i-1]!=0)
            tr[j][i] = tr[tr[j][i-1]][i-1];
        }
    }
}


int LCA(int a,int b){
    if(L[a]>L[b])   swap(a,b);
    int sz = log2(n);
    for(int i = sz; i>=0; i--)  if(L[b]-(1<<i)>=L[a])   b = tr[b][i];
    for(int i = sz; i>=0; i--)  if(tr[a][i]!=0 && tr[a][i]!=tr[b][i]) a = tr[a][i],b = tr[b][i];
    if(a==b)    return a;
    return par[a];
}




main(){
//read;

TT{

si(n);

clr();

ara[n] = 2;

for(int i = 1; i<n; i++){
    int a,b;
    sii(a,b);
    v[a].push_back(b);
    v[b].push_back(a);
}

for(int i = 0; i<=n; i++){
    if(SZ(v[i])>2)  ara[n] = 0;
}

dfs(0,-1);
build();


for(int i:v[0]){
    ll a = sub[i];
    ara[0]+=a*(a-1);
}


int x = 1,p;

while(x!=-1){
    vis[x] = 1;
    if(par[x]==0)   p = x;
    x = par[x];
}

for(int i:v[0]){
    if(i!=p){
        ara[1]+=sub[i]*(n - 1 - sub[1]-sub[i]);
    }
    else{
        ll w =(sub[i] - sub[1])*( n - 1 - sub[i]);
        ara[1]+=w;
    }
}

ara[1]+=2*(n-1-sub[1]);

x = 0;
int y = 1,q = -1;

//cout<<endl;

for(int i = 2; i<n; i++){
    if(vis[i])  continue;
    int tmp,lca = LCA(y,i);
    ll a,b;
//    cout<<"QQ "<<i<<" "<<x<<" "<<y<<endl;
    if(lca==y){
        a = sub[y] - sub[i];
        if(x==0)    b = sub[0] - sub[p];
        else b = sub[x];
        ara[i] = 2*a*b;
        tmp = i;
        while(tmp!=y){
            vis[tmp] = 1;
            tmp = par[tmp];
        }
        y = i;
    }
    else if( ( x && LCA(i,x)==x ) ||  ( x==0 && LCA(i,p)!=p) ){
        if(x==0){
            a = sub[0] - sub[p] - sub[i];
        }
        else a = sub[x] - sub[i];
        b = sub[y];
        ara[i] = 2*a*b;
        tmp = i;
        while(tmp!=x)   vis[tmp] = 1, tmp = par[tmp];
        x = i;
    }
    else{
        a = sub[0] - sub[p];
        if(x)   a = sub[x];
        b = sub[y];
        ara[i] = 2*a*b;
        break;
    }
//    cout<<"WW "<<i<<" "<<x<<" "<<y<<endl<<endl;
}

for(int i = 0; i<=n; i++){
    printf("%lld ",ara[i]/2);
}

cout<<endl;

}

return 0;
}