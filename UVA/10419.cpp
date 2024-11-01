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
#define TT                      long long TC;  scanf("%lld",&TC);  FOR(tc,TC)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
#define                         case printf("CASE %d:\n",++tc);
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;

vector<int> prime = {2};

void sieve(){
    const int size = 300;
    bitset<size+5> mark;
    for(ll i = 3; i*i<size; i+=2) if(mark[i]==0) for(ll j = i*i; j<size; j+=2*i)   mark[j] = 1;
    for(ll i = 3; i<size; i+=2)   if(mark[i]==0)    prime.push_back(i);
}

int dp[65][1002][15];

int fn(int pos,int n,int cnt){
    if(n==0 && cnt==0)  return dp[pos][n][cnt] = 1;
    if( n<=0 || cnt==0 || pos==(int)prime.size() )  return 0;
    int &ans = dp[pos][n][cnt];
    if(ans!=-1) return ans;
    ans = 0;
    if( cnt>1 && prime[pos]!=2 ){
        bool fl = fn(pos+1, n - 2*prime[pos],cnt-2);
        if(fl)  return ans = 1;
    }
    bool fl = fn(pos + 1, n - prime[pos], cnt-1);
    if(fl)  return ans = 1;
    return ans = fn(pos+1,n,cnt);
}

bool flag;
vector<int> v,V;

void solve(int pos,int n,int cnt){
    if(flag)    return;
    if(n==0 && cnt==0){
        V = v;
        v.clear();
        flag = 1;
        return;
    }
    if( n<=0 || cnt==0 || pos==(int)prime.size() )  return;
    if(dp[pos][n][cnt]!=1)  return;

    if(cnt>1 && prime[pos]!=2 && n>=2*prime[pos] && dp[pos+1][n-2*prime[pos]][cnt-2]==1){
        v.pb(prime[pos]);
        v.pb(prime[pos]);
        solve(pos+1,n-2*prime[pos],cnt-2);
        return;
    }
    if(n>=prime[pos] && dp[pos+1][n-prime[pos]][cnt-1]==1){
        v.pb(prime[pos]);
        solve(pos+1,n - prime[pos],cnt-1);
        return;
    }
    solve(pos+1,n,cnt);
}

bool cmp(int x,int y){
    stringstream a,b;
    a<<x;
    b<<y;
    return a.str() < b.str();
}

main(){
//read;
sieve();

sort(all(prime),cmp);

int tc = 0;

while(1){
    V.clear();
    v.clear();
    int n,k;
    scanf("%d%d",&n,&k);
    if(n==0 && k==0)    break;


    case;
    memset(dp,-1,sizeof dp);
    flag = 0;
    int ans = fn(0,n,k);
    if(ans==0){
        puts("No Solution.");
        continue;
    }
    solve(0,n,k);
    for(int i = 0; i<(int)V.size(); i++){
        if(i)   printf("+");
        printf("%d",V[i]);
    }
    puts("");
}


return 0;
}

