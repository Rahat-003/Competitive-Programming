#include                        <bits/stdc++.h>
#include                        <ext/pb_ds/assoc_container.hpp>
#define lb                      lower_bound
#define ub                      upper_bound
#define fe(x)                   (*(x.begin()))
#define si(a)                   scanf("%d",&a)
#define sii(a,b)                scanf("%d %d",&a,&b)
#define siii(a,b,c)             scanf("%d %d %d",&a,&b,&c)
#define sl(a)                   scanf("%lld",&a)
#define sll(a,b)                scanf("%lld %lld",&a,&b)
#define slll(a,b,c)             scanf("%lld %lld %lld",&a,&b,&c)
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

#define mx 10002
ll n,k,x;

ll dp[mx];


ll fn(ll sum){
	if(sum>n)	return 0;
	if(sum==n)	return 1;
	ll &ans = dp[sum];
	if(ans!=-1)	return ans;
	ans = 0;
	ans = (ans + fn(sum+1));
	ans = (ans + fn(sum+x));
	ans = (ans + fn(sum*7));
	return ans;
}


main(){
//read;

sll(n,k);


ll l = 2,r = n-1,m,ans = 0,qq = 0;

while(l<=r){
	m = l+r>>1;
	memset(dp,-1,sizeof dp);
	x = m;
	ll w = fn(1);
//	cout<<"HI "<<x<<" "<<w<<endl;
	if(w>=k){
		if(w==k)	ans = x;
		l = m+1;
	}
	else r = m-1;
}

//puts("0");

cout<<ans;


return 0;
}
