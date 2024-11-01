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

vector<ll> v = {0,0,0,1};
void make(){
	
	ll p = 1;
	///tribonacci
	
	while(v.size()<=32){
		ll sz = v.size();
		ll x = v[sz-1] + v[sz-2] + v[sz-3];
		p*=2;
		v.push_back(p+x);
	}
}

int main(){
make();
ll n;
while(1==scanf("%lld",&n)){
	if(!n)	break;	
	printf("%lld\n",v[n]);
	
}

return 0;
}

