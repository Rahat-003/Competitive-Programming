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
#define mx (ll)5e7

ll ar[mx];
ll lmt;
void make(){

ll p  = 2;	

for(ll i = 4; i<mx; i++){
	ar[i] = ar[i-1] + p ;
	p++;
	}
}
/*
ll binsearch(ll l, ll h,ll x){
    ll m= (l+h)/2;
    if(ar[m]==x) return m;

		if(x<ar[0])	return 0;

	if(l==h){
		if(ar[h]>x)	return h;
		return h+1;
	}
	
	if(h-l==1){
		if(ar[l]>x)	return l;
		if(ar[h]>x)	return h;
	}

    if(x>ar[m]) return binsearch(m+1,h,x);
    else return binsearch(l,m-1,x);
}
*/


int main(){
//	read;
	make();
ll n ;
int tc = 0;
/*
string s = to_string(ar[mx-1]);
cout<<s.size()<<endl;
*/
while(1==scanf("%lld",&n)){
	if(!n)	break;
	
//	ll p = binsearch(0,mx-1,n);
	ll p = lower_bound(ar,ar+mx,n) - ar;
	printf("Case %d: %lld\n",++tc,p);	
}

return 0;
}

