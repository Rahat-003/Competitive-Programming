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
#define TT                      long long TC;  scanf("%lld",&TC);  while(TC--)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
#define FF                      fflush(stdout);
#define assign(v,n,x)           v.clear(); for(int I = 0; I<n; I++)    v.pb(x);
#define SZ(x)                   (int)x.size()
#define ff                      first
#define ss                      second
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;


#define mx 1000

int dp[mx+3];

vector<int> v;


int fn(int pos){
    if(pos<0)   return mx;
    if(pos==0)   return 0;
    int &ans = dp[pos];
    if(ans!=-1) return ans;
    ans = mx;
    for(int i:v){
        ans = min(ans,1 + fn(pos-i));
    }
    return ans;
}





main(){
//read;


memset(dp,-1,sizeof dp);

//v = {1,16,58,128};
v = {1,15,32,123};

int ans = 0,x;

for(int i = mx; i; i--){
    ans = max(ans,fn(i));
    if(ans==dp[i])  x = i;
}

//cout<<x<<" "<<ans<<endl;

//for(int i = 1; i<=10; i++)
//    cout<<"HI : "<<i<<" "<<dp[i]<<endl;
dp[0] = 0;

TT{
    int n;
    si(n);
    cout<<dp[n]<<endl;
    while(n>0){
        for(int i:v){
            if(i<=n && dp[n]-1==dp[n-i]){
                cout<<i<<" ";
                n-=i;
                break;
            }
        }
    }
    cout<<endl;
    FF;
    string s;
    cin>>s;
}


return 0;
}


