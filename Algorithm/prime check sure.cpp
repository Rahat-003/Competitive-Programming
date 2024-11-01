#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long LL;
#define ll LL
using namespace std;
#define pi acos(-1)

ll Pow(ll n, ll p, ll m) {
	if(!p) return 1;
	else if(p & 1) return  (__int128)(n * Pow(n, p-1, m)) % m;
	else {
		ll v = Pow(n, p/2, m);
		return (v*v) % m;
	}
}

bool isprime(LL n){
	if(n<2) return false;
	for(LL i=2;i*i*i<=n;++i) if(n%i==0) return false;
	for(int it=0;it<1e5;++it){
		LL i = rand()%(n-1)+1;
		if(__gcd(i,n)!=1) return false;
		if(Pow(i,n-1,n)!=1) return false;
	}
	return true;
}


int main(){
int t,tc = 0;

ll n;
//while(cin>>n)	cout<<isprime(n)<<endl;
__int128 x = (1<<62ll);


return 0;
}

