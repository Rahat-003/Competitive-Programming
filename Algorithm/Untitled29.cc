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
int n;

int dp[mx][mx],ar[mx][mx],ara[mx][mx];
string s;

int fn(int pos,int last){
    if(pos==n)  return 0;
    int &ans = dp[pos][last];
    if(ans!=-1) return ans;
    ans = 0;
    ans = max(ans,fn(pos+1,last));
    if(last==n)    ans = max(ans, n - pos + fn(pos+1,pos) );
    else{
        if(ar[pos][last]){
            ans = max(ans, n - pos - ara[pos][last] + fn(pos + 1, pos ));
        }
    }
    return ans;
}


int solve(int i,int j){
    if(i==j)    return 0;
    if(j==n)    return 1;
    if(i==n)    return 0;
    int &ans = ar[i][j];
    if(ans!=-1) return ans;
    ans = 0;
    int a = s[i] - 'a',b = s[j] - 'a';
    if(a>b)     ans = 1;
    if(a<b)     ans = 0;
    if(a==b)    ans = solve(i+1,j+1);
    return ans;
}

int F(int i,int j){
    if(i==j || i==n || j==n)    return 0;
    if(s[i]>s[j])   return 0;
    int &ans = ara[i][j];
    if(ans!=-1) return ans;
    ans = 1 + F(i+1,j+1);
    return ans;
}

main(){
//read;

TT{
    cin>>n>>s;
    for(int i = 0; i<n+2; i++){
        for(int j = 0; j<n+2; j++){
            dp[i][j] = -1,
            ar[i][j] = -1,
            ara[i][j] = -1;
        }
//        dp[i] = vector<int> (n+5,-1);
//        ar[i] = dp[i];
//        ara[i] = dp[i];
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            ar[i][j] = solve(i,j);
//            if(ar[i][j])    cout<<j<<" ";
        }
//        cout<<endl;
    }

    for(int i = 0; i<n; i++){
//        cout<<i<<" -> ";
        for(int j = 0; j<n; j++){
            if(ar[i][j]){
                ara[i][j] = F(i,j);
//                cout<<"("<<j<<","<<ara[i][j]<<") ";
            }
        }
//        cout<<endl;
    }

    int ans = 0;
    ans = fn(0,n);
    cout<<ans<<endl;
}






return 0;
}

