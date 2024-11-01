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
#define mx 38

const ll M = 7+1e9;
const ll P = 31;

ll suf[mx],pref[mx],pwr[mx];

ll fn(ll a,ll b,ll c){
	if(b==0)	return 1;
	if(b==1)	return a%c;
	if(b%2==0){
		ll x = (fn(a,b/2,c))%c;
		return (x*x)%c;
	}
	ll x = fn(a,b-1,c)%c;
	return ((a%c)*(x%c))%c;
}
string s;

void H(){
	ll p = 1;
	for(ll i = 0; i<mx; i++){
		pwr[i] = p;
		p = (p*31)%M;
	}

	for(ll i = 0; i<s.size(); i++){
		ll a = s[i]	;
		pref[i] = (a*pwr[i])%M;
		if(i)  pref[i] = (pref[i] + pref[i-1])%M;
	}

	ll sz = s.size() - 1;
	for(ll i = sz; i>=0 ; i--){
		ll a = s[i];
		suf[i] = (a*pwr[sz-i])%M;
		if(i!=sz)	suf[i] = (suf[i] + suf[i+1])%M;
	}
}

int main(){

int t,tc = 0;
s = "IOIKIOOI";
H();
ll x,y,L,R,w;
while(cin>>L>>R){

//	L = 0,R = 7;
	w = s.size() - (R+2);
	x = ( (M + pref[R] - pref[L-1])*fn(P,M-L-1,M) )%M;
	y = ( (M + suf[L] - suf[R+1])*fn(P,M-2-w,M) )%M;
	if(x==y)	printf("[%lld...%lld] is palindrome\n",L,R);
	else printf("[%lld...%lld] is not palindrome\n",L,R);
	puts("");
}

return 0;
}

