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

vector<int> v[mx];

int start[mx],finish[mx];

int cnt;

int id[mx];
int segtree[mx*4];
int arr[mx],brr[mx];



int subtree[mx];



void dfs(int u,int a){
    start[u] = ++cnt;

    brr[cnt] = u;
    subtree[u]++;
    id[u] = cnt;
//    cout << start
    for(int i:v[u]){
        if(i==a)    continue;
        dfs(i,u);
        subtree[u]+=subtree[i];
    }
    finish[u] = cnt;
}

void initialize(int node,int b,int e)
{
    if(b==e)
    {
        segtree[node]=arr[brr[b]];
        return ;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    initialize(left,b,mid);
    initialize(right,mid+1,e);

    segtree[node]=segtree[left]+segtree[right];
}


int query(int node,int b,int e,int i,int j)
{
    if(i>e  || j<b)
    {
        return 0;
    }
    if(b>=i && e<=j)
    {
        return segtree[node];
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}


main(){
//read;


int n;
si(n);
for(int i=1;i<=n;i++)
{
    cin>>arr[i];
}
for(int i = 1; i<n; i++){
    int a,b;
    sii(a,b);
    v[a].pb(b);
    v[b].pb(a);
}

dfs(1,0);

//for(int i:v[6]){
//    cout << i << " ";
//}

cout << endl;
cout<<endl;

//for(int i = 1; i<=n; i++){
//    cout << "HI " << i << " " << start[i] << " " << finish[i] << endl;
//}

cout << endl;

for(int i = 1; i<=n; i++){
    cout << id[i] << " ";
}



    return 0;
}


