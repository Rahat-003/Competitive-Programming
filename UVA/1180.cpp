#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <memory.h>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("print.txt","w",stdout)
typedef unsigned long long ll;
using namespace std;
#define mx (ll)6e5+3
bool ar[mx];
vector<ll> prime;
void sieve(){
	ar[1] = ar[0] = true;
	/*
	for(ll i = 4; i<mx; i+=2)
		ar[i] = true;
		*/
	for(ll i = 3; i*i<=mx; i+=2){
		if(!ar[i]){
			for(ll j = i*i; j<mx; j+=2*i)
			ar[j] = true;
		}
	}
	prime.push_back(2);
	for(ll i = 3; i<mx; i+=2)
		if(!ar[i])	prime.push_back(i);
}

bool cal(ll n){
	if(n==19)	return false;
	ll M = 1, O = 1;
	
	for(ll i = 0; i<n; i++){
		O*=2;
	}
	M = (O/2)*(O-1);

	ll N = M;
	n=M;
	ll p = 1;
	ll ans = 1;
	for(ll i:prime){
		if(i>n)	break;
		if(n%i==0){
			ll Q = i;
			while(n%i==0){
				Q*=i;
				n/=i;
			}
			Q-=1;
			Q/=(i-1);
			ans*=Q;
		}

	}
	if(n>1){
		ll s = (n*n-1)/(n-1);
		ans*=s;
	}

	return (ans-N)==N;
}


int main(){
sieve();
int n;
scanf("%d",&n);
for(int i = 0; i<n; i++){
	char c;
	if(i) cin>>c;
	ll p;	scanf("%lld",&p);
	bool fl = cal(p);
	if(fl)	puts("Yes");
	else puts("No");	
}


return 0;
}

