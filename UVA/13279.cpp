#include <vector>
#include <cstdio>
typedef long long ll;
using namespace std;

#define mx 5000002

const ll M = 1e8+7;
bool ar[mx+3];

vector<ll> prime = {2};

void sieve(){
	for(ll i = 3; i*i<=mx; i+=2)	if(!ar[i])	for(ll j = i*i; j<mx; j+=2*i)	ar[j] = 1;
	for(ll i = 3; i<mx; i+=2)	if(!ar[i])	prime.push_back(i);
}

ll sum(ll F,ll L,ll D){
	ll T = 1+(L-F)/D;
	ll x = (L+F);
	if(x%2==0)	x/=2;
	else T/=2;
	ll ans = (x*T)%M;
	return ans;	
}

ll cl(ll n,ll x){
	ll y;
	ll ans = 0;
	ans = (sum((n-x+1)%x,n-x+1,x))%M;
	
	for(ll i = x*x; i<=n; i*=x){
		y = (sum( (n-i+1)%i,n-i+1,i ))%M;
//		cout<<y<<" ";
		ans = (ans+y)%M;
	}
//	cout<<endl;
	return ans;
}

ll fn(ll n){
	ll ans = 1;
	for(ll i = 0; i<prime.size(); i++){
		if(prime[i]>n)	break;
		ll x = ( cl(n,prime[i]) + 1 )%M;
		ans = (ans*x)%M;
	}
	return ans;
}

int main(){
sieve();
ll n;
while(1==scanf("%lld",&n)){
	if(!n)	break;
	ll ans = fn(n);
	printf("%lld\n",ans);
}


return 0;
}

