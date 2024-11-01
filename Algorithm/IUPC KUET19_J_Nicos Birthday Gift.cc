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
#define TT                      long long TC;  scanf("%lld",&TC);  rep(tc,1,TC)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
#define SZ(x)                   (int)x.size()
#define ff                      first
#define ss                      second
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;

#define mx 50050

int ar[2][mx],dp[2][mx][12];

int ara[100005];


main(){
//read;

TT{
    int n,m;
    sii(n,m);
    memset(ara,0,sizeof ara);
    memset(ar,0,sizeof  ar);
    memset(dp,0,sizeof dp);

    for(int i = 0; i<=1; i++)
        for(int j = 1; j<=n; j++)
            si(ar[i][j]);

    for(int i = n; i; i--){
        dp[1][i][0] = 1;
        for(int j = 0; j<=m; j++){
            int y = ar[1][i+j+1],x = ar[1][i];

            if(y>=x){
                for(int k = 0; k<=m; k++){
                    if(j+k>m)   break;
                    dp[1][i][j+k] = max(dp[1][i][j+k], 1 + dp[1][i+j+1][k]);
                }
            }
        }
        for(int j = 1; j<=m; j++)
            dp[1][i][j] = max(dp[1][i][j],dp[1][i][j-1]);

        int x = ar[1][i];
        ara[x] = max(dp[1][i][m], ara[x]);
    }

    printf("Case %d: ",tc);

    for(int i = 1; i<=n; i++){
        dp[0][i][0] = 1;
        for(int j = 0; j<=m; j++){
            if(i-j-1<=0)    break;
            int y = ar[0][i-j-1],x = ar[0][i];

            if(y<=x){
                for(int k = 0; k<=m; k++){
                    if(j+k>m)  break;
                    dp[0][i][j+k] = max(dp[0][i][j+k], 1 + dp[0][i-j-1][k]);
                }
            }
        }
        for(int j = 1; j<=m; j++)
            dp[0][i][j] = max(dp[0][i][j] , dp[0][i][j-1] );
    }


    for(int i = 100002; i>=0; i--)
        ara[i] = max(ara[i], ara[i+1]);

    int ans = ara[0];
    for(int i = 1; i<=n; i++){
        int x = ar[0][i];
//        cout<<"HI "<<x<<" "<<ara[x]<<" "<<dp[0][i][m]<<endl;
        ans = max(ans, dp[0][i][m] + ara[x]);
    }

    printf("%d\n",ans);

}
return 0;
}



