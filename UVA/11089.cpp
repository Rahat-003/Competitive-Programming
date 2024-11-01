#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <memory.h>
#include <algorithm>
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;

#define mx (ll)1e9
map<ll,ll> ar;
vector<ll> v = {0,1};
vector<ll> id;
void make(){
    ll x = 0;
    while(x<=mx){
        ll sz = v.size()-1;
        x = v[sz]+v[sz-1];
        if(x>mx)   break;
        v.push_back(x);
    }
    for(ll i = 2; i<v.size(); i++)
        ar[v[i]] = i-1;

}

ll check(ll n){
	ll i;
	for(i = 2; i<v.size(); i++)
		if(v[i]>n)	return i-1;
	
	return i-1;
}

string f(ll n){
    while(n>0 ){
    ll x = check(n);
    n-=v[x];
    if(!x)	break;
    id.push_back(v[x]);
	}
	
    string s;
	ll sz = ar[id[0]];
	for(int i = 0; i<sz; i++)
		s.push_back('0');

	
	for(int i = 0; i<id.size(); i++){
		s[sz-ar[id[i]]] = '1';
	}
		return s;
   
}

int main(){

make();


int t;
scanf("%d",&t);
while(t--){
    ll n;
    scanf("%lld",&n);
    string ans = f(n);
    printf("%s\n",ans.c_str());
    id.clear();
}


return 0;
}

