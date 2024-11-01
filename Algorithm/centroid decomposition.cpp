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

int subtree[mx],Node,centroids[mx];
vector<int> v[mx];
vector<int> Level[mx],centroid_tree[mx];

void DFS(int u,int a){
    subtree[u] = 1;
    Node++;
    for(int i:v[u]){
        if(i==a || centroids[i])    continue;
        DFS(i,u);
        subtree[u]+=subtree[i];
    }
}

int find_centroid(int u,int a){
    bool fl = 1;
    for(int i:v[u]){
        if(i==a || centroids[i])    continue;
        if(subtree[i]>Node/2) fl = 0;
        int x = find_centroid(i,u);
        if(x!=-1)   return x;
    }
    if( fl && Node - subtree[u]<=Node/2 )  return u;
    return -1;
}


void decompose(int root = 1,int p = 0,int lvl = 0){
    Node = 0;
    DFS(root,p);
    int x = find_centroid(root,p);
    if(x!=-1){
        centroids[x] = 1;
        centroid_tree[x].pb(p);
        centroid_tree[p].pb(x);
        Level[lvl].pb(x);
        for(int i:v[x]){
            if(centroids[i])    continue;
            decompose(i,x,lvl+1);
        }
    }
}



main(){
//read;


int n;
si(n);

for(int i = 1; i<n; i++){
    int a,b;
    sii(a,b);
    v[a].pb(b);
    v[b].pb(a);
}

decompose();

//cout<<endl;
for(int i = 0; i<=n; i++){
    if(SZ(Level[i])==0) continue;
    cout<<"HI "<<i<<" "<<Level[i].size()<<endl;
//    for(int j:L[i]){
//        cout<<j<<" ";
//    }
    cout<<endl<<endl;
}

return 0;
}


