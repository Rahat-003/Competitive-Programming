
#include <cstdio>
#include <unordered_map>
using namespace std;

typedef long long ll;

void fact(ll n,unordered_map<ll,ll> &mp){
	ll x = n;
	while(n%2==0 && n>1){
		mp[2]++;
		n/=2;
	}
	for(ll i = 3; i*i<=n; i+=2){
		while(n%i==0 && i>1){
			mp[i]++;
			n/=i;
		}
	}
	if(n>1)	mp[n]++;
}

ll factor(ll n, ll d){
	unordered_map<ll,ll> N,D;
	
//	fact(n,N);
	for(ll i = 2; i<=n; i++){
		fact(i,N);
	}
	fact(d,D);
	for(auto i:D){
		ll x = i.first;
		ll y = i.second;
		N[x]-=y;
		if(N[x]<0)	return 0;
	}
	ll ans = 1;
	for(auto i:N){
		ll x = i.first;
		ll y = i.second;
		ans*=(y+1);
	}
	return ans;
	N.clear();
	D.clear();
}

int main(){
	ll n,d;
	while(2==scanf("%lld %lld",&n,&d)){
		if(!n && !d)	break;
		ll ans = factor(n,d);
		printf("%lld\n",ans);
	}
	
	
	
	return 0;
}
