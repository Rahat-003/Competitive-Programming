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
#define FOR(i,n)                for(int i = 1; i<=n; i++)
#define REP(i,n)                for(int i = 0; i<n;  i++)
#define TT                      long long TC;  scanf("%lld",&TC);  while(TC--)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;
#define mx 100002

vector<int> v[mx];
bool vis[mx];
int dp[mx];

void dfs(int u){
    vis[u] = 1;
    int &ans = dp[u];
    ans = 1;
    for(int i:v[u]){
        if(!vis[i]) dfs(i);
        ans = max(ans,1 + dp[i]);
    }
}

main(){
//read;

int n,m;
cin>>n>>m;

/*
13 15

1 3
1 4
2 1
3 5
3 6
3 7
4 8
4 9
4 10
6 7
11 2
12 1
12 2
13 3
13 12

longest path 13-12-2-1-3-6-7
*/

vector<pii> V;

for(int i = 0; i<m; i++){
    int a,b;
    cin>>a>>b;
    v[a].pb(b);
}

int ans = 1;

for(int i = 1; i<=n; i++){
    if(vis[i]==false)   dfs(i);
}

for(int i = 1 ; i<=n; i++)
    ans = max(ans,dp[i]);

cout<<ans;

return 0;
}
