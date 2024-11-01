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


#define mx 4000002

int dp[mx];

int fn(int pos,int i){
    if(i==0)    return 0;
    int l = pos/(i+1);
    l++;
    int r = pos/i;
    return max(0,r - l + 1);
}

ll bigmod(ll n,ll p,ll m){
    if(p==0)    return 1;
    if(p==1)    return n%m;
    ll x = bigmod(n,p/2,m)%m;
    if(p%2==0)  return (x*x)%m;
    return (((x*x)%m)*(n%m))%m;
}



main(){
//read;


ll n,p = 1e9 + 7;
sll(n,p);

dp[1] = 2;
int tot = 0,sum = 0;

//cout<<fn(n,463)<<endl;

//vector<pint> v;

for(int i = n; i<=n; i++){
    tot = (tot + dp[i-1])%p;
    int ans = tot;
    int cnt = 0,last = -1;
    for(int j = 2; j<=i ; j++){
        int cur = i/j;
        int freq = fn(i,cur);
        if(fn(i,j)>0){
            int y = (1ll*dp[cur]*freq)%p;
                cout<<"HOLA "<<freq<<" "<<cur<<endl;
            ans = (ans+y)%p;
//            cnt++;
            last = j;
//            v.pb(pii(cur,freq));
        }
        else{
            for(int k = cur; k>=1; k--){
                freq = fn(i,k);
                int y = (1ll*dp[k]*freq)%p;
                ans = (ans+y)%p;
                cnt++;
//                v.pb(pii(k,freq));
            }
            break;
        }
    }
    cout<<"HI "<<cnt<<endl;
//    cout<<"HI "<<i<<" "<<cnt<<" "<<last<<endl;
    dp[i] = ans;
//    sum+=cnt;
}

//cout<<dp[n]<<endl;

ll q = bigmod(2ll,p-2,p);

ll ans = (1ll*dp[n]*q)%p;

cout<<ans;



return 0;
}


