#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)


ll fn(ll a,ll p,ll m){
	if(p==0)	return 1;
	if(p==1)	return a%m;
	if(p%2==0){
		ll x = fn(a,p/2,m);
		return ((x%m)*(x%m))%m;
	}
	else{
		ll x = fn(a,p-1,m);
		x%=m;
		return (x*(a%m))%m;
	}
}


int main(){
int t,tc = 0;
ll a,b,m;

while(3==scanf("%lld %lld %lld",&a,&b,&m)){
	
	ll x = a%m;
	ll y = fn(b,m-2,m);
	cout<<(x*y)%m<<endl;
	
}

return 0;
}

