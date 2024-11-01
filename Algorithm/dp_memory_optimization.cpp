/****
*
*   DP - Memory Optimization
*   https://codeforces.com/contest/1525/problem/D
*
*****/
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

#define mx 5002

vector<int> u,v;

int n,m,dp[2][mx];

main(){
//read;

si(n);

int ar[n];

for(int i = 0; i<n; i++)    si(ar[i]);

for(int i = 0; i<n; i++){
    if(ar[i]==0)    v.pb(i);
    else u.pb(i);
}

n = SZ(u);
m = SZ(v);

dp[0][m] = 1e9;
dp[1][m] = 1e9;

int ans = 0;

for(int i = n-1,fl = 0; i>=0; i--,fl^=1){
    for(int j = m-1; j>=0; j--){
        int x = 1e9,y = abs(u[i] - v[j]);
        if(i!=n-1)  y+=dp[!fl][j+1];
        x = dp[fl][j+1];
        dp[fl][j] = min(x,y);
    }
    ans = dp[fl][0];
}

cout << ans;


return 0;
}



