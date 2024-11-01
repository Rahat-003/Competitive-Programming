
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define mx 503

ll ar[mx];
vector<ll> v;

ll pp[19];
void g(){
	ll ans = 1;
	pp[0] = 1;
	for(ll i = 1; i<=18; i++){
		ans*=10;
		pp[i] = ans;
	}
	return;
}

ll tol(string s){
	ll sz = s.size()-1;
	ll ans = 0;
	for(ll i = 0; i<s.size(); i++){
		ll x = s[i] - '0';
		ans+= pp[sz-i]*x;
	}
	return ans;
}
string bina(ll n){
	string s;
	while(n){
		s.push_back( (9*(n%2)) +'0' );
		n/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}


void make(){
	ar[1] = ar[3] = ar[9] = 9;
	for(ll i = 1; i<30000; i++){
//		if(ar[i]) continue;
		string s = bina(i);
//		string s = "5";
		v.push_back(tol(s));
	}
	for(ll k = 0; k<v.size(); k++){
		ll i = v[k];
		for(ll j = 2; j<mx; j++){
			if(j>i)	break;
			if(ar[j])	continue;
			if(i%j==0)	ar[j] = i;
		}
	}
return;
}


int main(){

g();

make();
int t;

cin>>t;
while(t--){
	ll n;
	cin>>n;
	cout<<ar[n]<<endl;
}




return 0;
}

