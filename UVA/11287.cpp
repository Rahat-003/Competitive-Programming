#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;

#define mx 32000
vector<int> prime;

bool ar[mx];

void sieve(){
	prime.push_back(2);
	for(ll i = 3; i*i<=mx; i+=2)	if(!ar[i])	for(ll j = i*i; j<mx; j+=2*i)	ar[j] = 1;
	for(ll i = 3;i<mx; i+=2)		if(!ar[i])	prime.push_back(i);	 	
}

ll b(ll n,ll p,ll m){
	if(p==0)	return 1;
	if(p==1)	return n%m;
	if(p%2==0){
		ll	x = b(n,p/2,m);
		return (x*x)%m;
	}
	else {
		ll x = b(n,p-1,m);
		return (x*(n%m))%m;
	}
}
bool isP(ll n){
	for(auto i:prime){
		if(i*i>n)	break;
		if(n%i==0)	return false;
	}
	return true;
}

int main(){
	sieve();
ll p,a;
while(cin>>p>>a){
	if(!p && !a)		break;
	if(isP(p)){
		puts("no");	continue;
	}
	ll x = b(a,p,p);
	if(x==a)	puts("yes");
	else puts("no");
}


return 0;
}

