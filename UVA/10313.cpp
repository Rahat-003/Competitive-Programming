#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define write       freopen("out.txt","w",stdout)

const ll mx = 300;
ll dp[mx+2][mx+2];
ll n,a,b;
void f(){
	dp[0][0] = 1;
	for(ll i = 1; i<=mx; i++)
		for(ll j = i; j<=mx; j++)
			for(ll k = 1; k<=j; k++)
				dp[j][k]+=dp[j-i][k-1];
}

ll fn(){

		ll ans = 0;
		if(a==-1 && b==-1){
			for(ll i = 0; i<=300; i++)	ans+=dp[n][i];
		}
		else if(a!=-1 && b==-1){
			for(ll i = 0; i<=min(a,300ll); i++)	ans+=dp[n][i];
		}
		else{
			if(a>300)	return 0;
			for(ll i = a; i<=min(b,300ll); i++)	ans+=dp[n][i];
		}
		
		return ans;
}	

int main(){

ll t,tc = 0;
string s;
f();
while(getline(cin,s)){
	if(s.size()==0)	break;
	s = s + " -1 -1";
	istringstream iss(s);
	
	a = -1,b = -1;
	iss>>n>>a>>b;
	a = max(a,-1ll);
	b = max(b,-1ll);
	ll ans = fn();
	printf("%lld\n",ans);
}

return 0;
}

