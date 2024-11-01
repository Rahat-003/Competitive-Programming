#include                <bits/stdc++.h>
#define ff              first
#define ss              second
#define pb(x)           push_back(x)
#define dbg(a)          cout<< #a <<" --> "<<(a)<<endl;
#define read            freopen("tst.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> PP;

struct NumberTheory{
	vector<ll> prime = {2};
	vector<bool> ar;
	vector<ll> totient;
	vector<ll> sumdiv;
	vector<ll> mobius;
	vector<ll> bigdiv;
	void Sieve(ll n){
		ar.assign(n+1, 1);
		ar[1] = false;
		for(ll i = 3; i*i <= n; i+=2){
			if(ar[i]){
				for(ll j = i*i; j<=n; j += i*2){
					ar[j] = false;
				}
			}
		}
		for(ll i = 3; i<=n; i+=2)
            if(ar[i])   prime.pb(i);
	}

	ll phi(ll x){
		map<ll,ll> pf;
		ll num = 1; ll num2 = x;
		for(ll i = 0; prime[i]*prime[i] <= x; i++){
			if(x%prime[i]==0){
				num2/=prime[i];
				num*=(prime[i]-1);
			}
			while(x%prime[i]==0){
				x/=prime[i];
				pf[prime[i]]++;
			}
		}
		if(x>1){
			pf[x]++; num2/=x; num*=(x-1);
		}
		x = 1;
		num*=num2;
		return num;
	}

	bool isPrime(ll x){
		if(x==1) return false;
		for(ll i = 0; prime[i]*prime[i] <= x; i++){
			if(x%prime[i]==0) return false;
		}
		return true;
	}

	void SievePhi(ll n){
		totient.resize(n+1);
		for (int i = 1; i <= n; ++i) totient[i] = i;
		for (int i = 2; i <= n; ++i){
			if (totient[i] == i){
				for (int j = i; j <= n; j += i){
					totient[j] -= totient[j] / i;
				}
			}
		}
	}
	void SieveMob(ll n){
		mobius.resize(n+1,0);
		mobius[1] = 1;
		for (int i = 2; i <= n; ++i) {
			if (ar[i]) {
				mobius[i] = -1;				//i is ar
			}
			for (int j = 0; j < prime.size () && i * prime[j] <= n; ++j) {
				if (i % prime[j] == 0) {
					mobius[i * prime[j]] = 0;//ar[j] divides i
					break;
				} else {
					mobius[i * prime[j]] = mobius[i] * -1;	//ar[j] does not divide i
				}
			}
		}
	}

	void SieveSumDiv(ll n){
		sumdiv.resize(n+1);
		for(int i = 1; i <= n; ++i){
			for(int j = i; j <= n; j += i){
				sumdiv[j] += i;
			}
		}
	}

	ll getPhi(ll n){
		return totient[n];
	}

	ll getSumDiv(ll n){
		return sumdiv[n];
	}

	ll modpow(ll a, ll b, ll mod){
		ll r = 1;
		if(b < 0) b += mod*100000LL;
		while(b){
			if(b&1) r = (r*a)%mod;
			a = (a*a)%mod;
			b>>=1;
		}
		return r;
	}

	ll inv(ll a, ll mod){
		return modpow(a, mod - 2, mod);
	}

	ll invgeneral(ll a, ll mod){
		ll ph = phi(mod);
		ph--;
		return modpow(a, ph, mod);
	}

	void getpf(vector<PP>& pf, ll n){
		for(ll i = 0; prime[i]*prime[i] <= n; i++){
			int cnt = 0;
			while(n%prime[i]==0){
				n/=prime[i]; cnt++;
			}
			if(cnt>0) pf.pb(PP(prime[i], cnt));
		}
		if(n>1){
			pf.pb(PP(n, 1));
		}
	}

	//ll op;
	void getDiv(vector<ll>& div, vector<PP>& pf, ll n, int i){
		//op++;
		ll x, k;
		if(i >= pf.size()) return ;
		x = n;
		for(k = 0; k <= pf[i].ss; k++){
			if(i==int(pf.size())-1) div.pb(x);
			getDiv(div, pf, x, i + 1);
			x *= pf[i].ff;
		}
	}
};



main(){
//read;

NumberTheory x;
x.Sieve(100);
for(ll i:x.prime)
    cout<<i<<" ";


return 0;
}

