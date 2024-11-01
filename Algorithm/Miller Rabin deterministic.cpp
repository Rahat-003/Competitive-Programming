#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


//	999999999999999989 is Prime

long long mulmod(ll a,ll b,ll c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2==1)  x = (x+y)%c;
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
vector<ll> Primes = {2,3,5,7,11,13,17,
                    19,23,29,31,37};
ll bigmod(ll b,ll p,ll m){
    if(p==0)    return 1;
    if(p==1)    return b%m;
    ll x;
    if(p%2==0){
        x = bigmod(b,p/2,m);
        return mulmod(x,x,m);
    }
    x = bigmod(b,p-1,m);
    return mulmod(x,b,m);
}

bool check(ll a,ll s,ll d,ll n){
    ll x = bigmod(a,d,n);
    if(x==1 || x==n-1)  return true;
    for(ll i = 1; i<s; i++){
        x = mulmod(x,x,n);
        if(x==n-1)  return true;
    }
    return false;
}

bool isPrime(ll n){
    if(n<4) return n==2 || n==3;
    if(n%2==0)  return false;
    ll s = 0,d = n-1;
    while(d%2==0){
        s++; d/=2;
    }
    for(ll i:Primes){
    	if(n==i)	return true;
        if(!check(i,s,d,n)) return false;
    }
    return true;
}


int main(){
int t,tc = 0;

ll n;

//ll a,b,c;
//while(cin>>a>>b>>c)
//    cout<<mulmod(a,b,c)<<endl;

while(cin>>n)	cout<<isPrime(n)<<endl;


return 0;
}

