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

#define mx 1002
ll n,k,x;

ll dp[mx];
bool fl;

bool check(ll a,ll b,ll c){
	if(c-b<a)	return 1;
	return 0;
}

ll fn(ll sum){
	if(fl)	return 0;
	if(sum>n)	return 0;
	if(sum==n)	return 1;
	ll &ans = dp[sum];
	if(ans!=-1)	return ans;
	ans = 0;
//	ans = (ans + fn(sum+1));
//	ans = (ans + fn(sum+x));
//	ans = (ans + fn(sum*7));
	ll p = fn(sum+1),q = fn(sum+x),r = fn(sum*7);
	if(check(p,q,k)==0)	p+=q;
	else{
		fl = 1;
		return 0;
	}
	
	if(check(p,r,k)==0)	p+=r;
	else{
		fl = 1;
		return 0;
	}
	
	return ans = p;
}


main(){
//read;

sll(n,k);

for(x = 2; x<n; x++){
	memset(dp,-1,sizeof dp);
	fl = 0;
	ll ans = fn(1);
	
//	cout<<"HI "<<x<<" "<<ans<<endl;
	if(ans==k && fl==0){
		cout<<x;
		return 0;
	}
}

puts("0");


return 0;
}


