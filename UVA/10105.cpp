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
#define mx 14
ll fact[mx] = {1,1,2};
void m(){
	for(ll i = 3; i<mx; i++)
		fact[i] = i*fact[i-1];
}

int main(){
m();
ll n,k;
while(2==scanf("%lld %lld",&n,&k)){
	ll T = fact[n];
	
	for(ll i = 0; i<k; i++){
		ll x;
		scanf("%lld",&x);
	T/=fact[x];
	}
	printf("%lld\n",T);
}


return 0;
}

