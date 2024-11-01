
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define ll long long


double L(ll n,ll b){
	return log10(n)/log10(b);
}
unordered_map<ll,ll> num,base;

void factor(ll n, unordered_map<ll,ll> &mp){
	while(n%2==0 && n){
		mp[2]++;
		n/=2;
	}
	for(ll i = 3; i*i<=n; i+=2){
		while(n%i==0 && n){
			mp[i]++;
			n/=i;
		}
	}
	if(n>1)
		mp[n]++;

}

ll zero(ll n,ll b,ll &digit){
	ll cnt = 0, x = b;
	double t = 0;

	for(ll i = 2; i<=n; i++){
		t+=L(i,b);
        factor(i,num);

	}

	ll mx = (ll)2e7,ans = mx;

	factor(b,base);
	for(auto it:base){
        ll f = it.first;
        ll t = it.second;
        ll Div = num[f]/t;
        ans = min(Div,ans);
	}


	digit = t+1;
	return ans;

}


int main(){
//    freopen("tst.txt","r",stdin);

ll n,b;
while(scanf("%lld %lld",&n,&b)==2){
    ll m;
    ll x = zero(n,b,m);
    printf("%lld %lld\n",x,m);
    num.clear();
    base.clear();
}





return 0;
}
