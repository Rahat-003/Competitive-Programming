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
#define TT                      long long TC;  scanf("%lld",&TC);  while(TC--)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;


ll fun(ll a, ll b, ll mod)
{
	return (a*a+b)%mod+1;
}

ll pollard_rho(ll num, ll comp)
{
	if(num==1) return 1;
	if(num%2 == 0) return 2;

	srand(time(0));
	ll y=rand()%num+1,c=rand()%num+1, x, gcd=1, sq=sqrt(num)+100;
	x=y;

	int count=0;

	while(gcd==1)
	{
		if(count >= sq) return num;
		count++;
		x=fun(x, c, num);
		y=fun( fun(y, c, num), c, num );
		if(x==y) gcd=num;
		else	gcd=__gcd(abs(x-y), num);
		if(gcd!=1)
		{
			if(gcd==num || gcd==comp)
			{
				y=rand()%num+1;
				x=y;
				gcd=1;
			}
			else
			{
				break;
			}
		}
	}

	return gcd;
}

ll bigmod(ll base, ll power, ll mod)
{
	ll res=1;
	while(power)
	{
		if(power&1) res=(res*base)%mod;
		power>>=1;
		base=(base*base)%mod;
	}
	return res;
}


bool miller_rabin(ll num, ll k)
{
	ll s=0,d=num-1,one=1,temp;
	while(!(d&1)) d>>=1,s++;

	bool flag=true;
	temp=bigmod(k,d,num);
	if(temp==1 || temp==num-1) return 1;
	for(int i=0;i<s;i++)
	{
		temp=(temp*temp)%num;
		if(temp==1) return 0;
		if(temp==num-1) return 1;
	}
	return 0;
}

bool prime(ll num)
{
	vector<int>A{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
	for(auto x:A) if(x==num) return 1;
	if(!(num&1)) return 0;

	bool flag=true;
	for(auto x:A) flag&=miller_rabin(num, x);
	return flag;
}

vector<pll> prime_factorization(ll x){

	vector<pll>factor;

	if(x==0) return factor;


	while(x!=1)
	{
		ll y=pollard_rho(x,0);
		int count=1;
		while(!prime(y)) y=pollard_rho(y,y);
		x/=y;
		while(x%y==0)
		{
			x/=y;
			count++;
		}
		factor.push_back({y,count});
	}
	sort(factor.begin(),factor.end());
//	for(auto o: factor){
//		cout<<o.first;
//		cout<<"^"<<o.second<<" ";
//	}
//	cout<<"\n";
    return factor;
}

ll sum(ll a,ll b){
    if(a>b) return 0;
    a--;
    return b*(b+1)/2 - a*(a+1)/2;
}

vector<ll> primes = {2};

void sieve(){
    const int size = 1000015;
    bitset<size> mark;
    for(ll i = 3; i*i<size; i+=2) if(mark[i]==0) for(ll j = i*i; j<size; j+=2*i)   mark[j] = 1;
    for(ll i = 3; i<size; i+=2)   if(mark[i]==0)    primes.push_back(i);
}

vector<pll> factorize(ll n){
    vector<pll> v;
    for(ll i:primes){
        if(i*i>n)   break;
        if(n%i) continue;
        ll cnt = 0;
        while(n%i==0){
            n/=i;
            cnt++;
        }
        v.pb({i,cnt});
    }
    if(n>1) v.pb({n,1});
    return v;
}

main(){
//read;

sieve();
int tc = 0;
TT{
    ll n,ans = 0,MOD = 1000009;
    scanf("%lld",&n);
    printf("Case %d: ",++tc);
    //cout<<n<<endl;
    //prime_factorization(n);
    //cout<<endl;
    for(ll i = 2; i*i<=n; i++){
        ll l = n/(i+1)+1,r = n/i;
        ll x = (i-1)*sum(l,r);
        ll y = i*(n/i - 1);
        if(i!=n/i)  ans+=x;
//        ans+=y;
        ans = (ans + y)%MOD;
    }

//    cout<<ans<<endl;
    vector<pll> v;
//    v = prime_factorization(ans);
    v = factorize(ans);
    ans = 0;
    for(auto i:v){
        ans = (ans + i.first*i.second)%MOD;
    }
    printf("%lld\n",ans);
}

return 0;
}

