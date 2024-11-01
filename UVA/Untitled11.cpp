#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const int mod=1e9+7;
ll s[N];
ll res[N];
ll sum;
map<ll,int> ma;
ll quick_pow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	int n;
	ll x;
	scanf("%d %lld",&n,&x);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
		sum=sum+s[i];
	}
	/*if(n==1){
		printf("%lld\n",quick_pow(x,sum));
		return 0;
	}*/
	for(int i=1;i<=n;i++){
		res[i]=sum-s[i];
	}
	sort(res+1,res+1+n);
	for(int i=1;i<=n;i++){
		ma[res[i]]++;
		ll tt=res[i];
		while(ma[tt]>=x){
			ma[tt]-=x;
			tt++;
			ma[tt]++;
		}
	}
	ll mini=-1;
	for(auto p:ma){
		if(p.second==0) continue;
		if(mini==-1) mini=p.first;
		mini=min(mini,p.first);
	}
	mini=min(mini,sum);
	printf("%lld\n",quick_pow(x,mini));
}
