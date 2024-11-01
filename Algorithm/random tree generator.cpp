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
#define read                    freopen("tst.txt","r",stdin)
#define write                   freopen("input.txt","w",stdout)
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


vector<pair<int,int>> pruferCodeToTree(vector<int> &pruferCode) {
    // Stores number count of nodes in the prufer code
    unordered_map<int,int> nodeCount;

    // Set of integers absent in prufer code. They are the leaves
    set<int> leaves;

    int len = pruferCode.size();
    int node = len + 2;

    // Count frequency of nodes
    for ( int i = 0; i < len; i++ ) {
        int t = pruferCode[i];
        nodeCount[t]++;
    }

    // Find the absent nodes
    for ( int i = 1; i <= node; i++ ) {
        if ( nodeCount.find ( i ) == nodeCount.end() ) leaves.insert ( i );
    }

    vector<pair<int,int>> edges;
    /*Connect Edges*/
    for ( int i = 0; i < len; i++ ){
        int a = pruferCode[i]; // First node

        //Find the smallest number which is not present in prufer code now
        int b = *leaves.begin(); // the leaf

        edges.push_back({a,b}); // Edge of the tree

        leaves.erase ( b ); // Remove from absent list
        nodeCount[a]--; // Remove from prufer code
        if ( nodeCount[a] == 0 ) leaves.insert ( a ); // If a becomes absent
    }

    // The final edge
    edges.push_back({*leaves.begin(), *leaves.rbegin()});
    return edges;
}

vector<int> v[2000002];

vector<pii> xx;

void dfs(int u,int a){
    int p = u,q = a;
    if(a)   xx.pb(pii(a,u));
    for(int i:v[u]){
        if(i==a)    continue;
        dfs(i,u);
    }
}

main(){

//write;

int n;
cin>>n;

cout<<endl<<endl<<endl;

cout<<n<<endl;

vector<int> pruferCode;

for(int i = 0; i<n-2; i++){
    ll x,y,z;
//    sl(x);
    x = rand()%12132568,y = rand()%47570,z = rand()%10521845;
    x = (x+y+z);
    if(rand()%14==0)  x+=rand()%52329;
    x%=n;
    x++;
//    cout<<x<<" ";
    pruferCode.pb(x);
}

//cout<<endl;

vector<pii> edges = pruferCodeToTree(pruferCode);

//cout<<SZ(edges)+1<<endl;

for(int i = 0; i<edges.size(); i++){
    if(edges[i].first>edges[i].second)  swap(edges[i].first,edges[i].second);
    int a = edges[i].ff,b = edges[i].ss;
    v[a].pb(b);
    v[b].pb(a);
}

sort(all(edges));

dfs(1,0);


for(auto i:xx){
    int p = i.ff,q = i.ss;
//    if(p>q) swap(p,q);
    printf("%d %d\n",p,q);
}






return 0;
}

