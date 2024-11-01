#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <iostream>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("print.txt","w",stdout)
typedef long long ll;
using namespace std;
#define mx (int)1e6+3
bool ar[mx/5+3],mark[mx];
vector<ll> prime;

void sieve(){
	for(ll i = 5; i<mx/5; i+=4){
	if(!ar[i])
		for(ll j = i*i; j<mx/5; j+=4*i){
			ar[j] = true;	
		}
	}

	
	for(ll i = 5; i<mx/5; i+=4)
		if(!ar[i])	{	
		prime.push_back(i);
		}

}
ll tot[mx];
void bal(){
	for(int i = 0 ; i<prime.size(); i++){
		int x = prime[i];
		for(int j = i; j<prime.size() && x*prime[j]<mx; j++){
		int y = prime[j];
		if(!ar[x] && !ar[y]){
			mark[x*y] = true;
		}
		}
	}
	for(ll i = 1; i<mx; i++){
		tot[i] = tot[i-1];
		if(mark[i])	tot[i]++;
	}

}

int main(){
sieve();
bal();
//read;
ll n;
while(1==scanf("%lld",&n)){
	if(!n)	break;
	int ans = 0;	
	printf("%lld %lld\n",n,tot[n]);
}


return 0;
}

