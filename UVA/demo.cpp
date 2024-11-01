/*
#include <cstdio>
#include <iostream>
#include <memory.h>
#include <sstream>
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const ll mx = 300;
ll dp[mx+2][mx+2];
ll n,a = -1,b = -1;
ll f(){
	dp[0][0] = 1;
	for(ll i = 1; i<=mx; i++)
		for(ll j = i; j<=mx; j++)
			for(ll k = 1; k<=j; k++)
				dp[j][k]+=dp[j-i][k-1];
}

ll fn(){
	if(a>300)	return 0;
	if(!n){
		if(a==1 && b==1)	return 0;
		else if(b>1)	return 0;
		else if(a<=1 )	return 1;
	}

		if(a==-1 && b==-1)	a = 1,b = n;
		if(a!=-1 && b==-1)	b = a,a = 1;
		b = min(b,n);
		ll ans = 0;
		for(ll i = a; i<=b; i++)	ans+=dp[n][i];
		return ans;
}

int main(){

freopen("tst.txt","r",stdin);

ll t,tc = 0;
string s;
f();
while(getline(cin,s)){
        ++tc;
	if(s.size()==0)	break;
	s = s + " -1 -1";
	istringstream iss(s);

	a = -1,b = -1;
	iss>>n>>a>>b;
	ll ans = fn();
//	printf("%lld\n",ans);
//	cout<<a<<" "<<b<<endl;
    if(tc==114) cout<<s<<endl;
}

return 0;
}

