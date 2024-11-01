
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
unordered_map<ll,ll> num,lcm;
/*
#define mx (int)1e7+5
bool ar[mx];

void sieve(){
    ar[0] = ar[1] = 1;

    for(int i = 4; i<mx; i+=2)
        ar[i] = 1;

    for(int i = 3; i*i<=mx; i+=2){
        if(!ar[i]){
            for(int j = i*i; j<mx; j+=2*i)
                ar[j] = 1;
        }
    }
}
*/
void factor(ll n, unordered_map<ll,ll> &mp){
	while(n%2==0 && n){
		mp[2]++;
		n/=2;
	}
	for(ll i = 3; i*i<=n; i+=2){
		while(n%i==0 && n){
			mp[i]++;
			n/=i;
		}
	}
	if(n>1)
		mp[n]++;

}

ll funct(){
    ll ans = 1;

    for(auto it:lcm){
        ll p = it.first;
        ll q = it.second;
        ll n = 0;
        if(q>num[p])
            n = q;

        for(ll i = 0; i<n; i++)
            ans*=p;
    }

    return ans;

}


int main(){


ll n,l,t;
scanf("%lld",&t);

while(t--){
    scanf("%lld %lld",&n,&l);
    if(l%n!=0){
        printf("NO SOLUTION\n");
        continue;
    }

    factor(n,num);
    factor(l,lcm);

    ll ans = funct();
    printf("%lld\n",ans);

num.clear();
lcm.clear();

}

return 0;
}
