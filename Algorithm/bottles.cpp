#include                        <bits/stdc++.h>
#include                        <ext/pb_ds/assoc_container.hpp>
#define lb                      lower_bound
#define ub                      upper_bound
#define fe(x)                   *(x.begin())
#define le(x)                   *(x.rbegin())
#define pb                      push_back
#define load(node,n)            bool operator < (const node &n) const
#define fbo(x)                  find_by_order(x)
#define ook(x)                  order_of_key(x)
#define all(x)                  (x).begin(),(x).end()
#define FOR(i,n)                for(int i = 1; i<=n; i++)
#define REP(i,n)                for(int i = 0; i<n;  i++)
#define TT                      int TC;  scanf("%d",&TC);  while(TC--)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;


#define mx 102

pll dp[mx][10002];
ll ar[mx],ara[mx],r[mx];

main(){
//read;

ll n,sum = 0;
cin>>n;

for(ll i = 1; i<=n; i++){
    cin>>ar[i];
    sum+=ar[i];
}
for(ll i = 1; i<=n; i++){
    cin>>ara[i];
    r[i] = ara[i]-ar[i];
}

for(ll i = 0; i<mx; i++){
    for(ll j = 0; j<=sum; j++)
    dp[i][j] = {-1e9,0};
}

dp[0][sum] = {0,0};
cout<<endl<<sum<<endl;

for(ll i = 1; i<=n; i++){
    for(ll j = sum; j>=0; j--){
        dp[i][j] = max(dp[i][j],dp[i-1][j]);

        if(j>=ar[i] && dp[i][j-ar[i]].first<j-ar[i]){
            pll x;
            x = max(dp[i][j-ar[i]],{dp[i][j].first + r[i],1+dp[i][j].second});
            dp[i][j-ar[i]] = x;
        }

    }
}

ll a = n,b = sum;
cout<<endl;

for(ll i = 1; i<=n; i++){
    for(ll j = 0; j<=sum; j++){
        pll x = dp[i][j];
        if(x.first>=j){
            cout<<i<<" "<<j<<" -> ";
            cout<<"HI "<<x.first<<" "<<j<<" "<<x.second<<endl;
            a = min(a,x.second);
        }
    }
}

for(ll i = 1; i<=n; i++){
    for(ll j = 0; j<=sum; j++){
        pll x = dp[i][j];
        if(x.first>=j && a==x.second){
            b = min(b,x.first);
        }
    }
}

cout<<a<<" "<<b;

return 0;
}
