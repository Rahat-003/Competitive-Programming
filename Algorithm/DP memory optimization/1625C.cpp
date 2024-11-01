/**
    Road Optimization
    https://codeforces.com/contest/1625/problem/C
*/

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

#define mx 502

int ar[mx],ara[mx];

int n,L,K;

int dp[2][mx][mx];

int fn(int pos,int last,int used){
    if(pos==n){
        if(used<n-K)    return mx;
        return (L-ar[last])*ara[last];
    }

    int &ans = dp[pos][last][used];
    if(ans!=-1) return ans;
    ans = fn(pos+1,last,used);
    ans = min(ans, (ar[pos]-ar[last])*ara[last] +  fn(pos+1,pos,used+1) );
    return ans;
}


main(){
//read;


ms(dp,infi);

siii(n,L,K);

for(int i = 0; i<n; i++)    si(ar[i]);
for(int i = 0; i<n; i++)    si(ara[i]);


int ans = 0;

for(int i = 1; i<n; i++){
    ans+=(ar[i] - ar[i-1])*ara[i-1];
}

ans+=(L-ar[n-1])*(ara[n-1]);

dp[0][0][0] = 0;

int must = n-K-1,flag = 0;

for(int pos = 1,fl = 1; pos<n; pos++,fl^=1){
    for(int last = 0; last<pos; last++){
        for(int used = 1; used<=pos; used++){
            int x,y;    //= infi,y = infi;
            x = dp[!fl][last][used-1];
            dp[fl][last][used-1] = min(dp[fl][last][used-1],x);

            y = (ar[pos] - ar[last])*ara[last] + dp[!fl][last][used - 1];
            dp[fl][pos][used] = min(dp[fl][pos][used],y);
        }
    }
    flag = fl;
}

for(int i = 0; i<n; i++){
    for(int j = must; j<=n; j++){
        int p = dp[flag][i][j] + (L-ar[i])*ara[i];
        ans = min(ans,p);
    }
}

cout<<ans<<endl;




return 0;
}



