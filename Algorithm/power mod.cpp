#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
  if( b%a==0 )  return a;
  return gcd(b%a, b );
}

ll bMod(ll n,ll p,ll m){
    if(p==0)    return 1;
    if(p==1)    return n%m;

    if(p%2==0){
        ll x = bMod(n,p/2,m);
        return ((x*x)%m);
    }
    else{
        ll y = bMod(n,p-1,m)%m;
        return ( (n%m)*y )%m;
    }
}
//*/

/*
ll M(ll b,ll p,ll m){
  if(m==1)  return 0;
  if(p==0)  return 1;
  if(p==1)  return b%m;

  ll x = b%m;
  ll ans = (x*x)%m;

  return (ans*M(b,p-2,m))%m;
}
*/

ll power(ll x, ll i,ll mod){
    ll ans = 1;
    while(i > 0)
    {
        if(i&1)
            ans = (ans*x)%mod;
        i >>=1;
        x = (x*x)%mod;
    }
    return ans;
}

main(){

ll b,p,m;

while(cin>>b>>p>>m){

  ll ans = power(b,p,m);
  ans = (ans%m + m)%m;

  cout<<ans<<endl;
}






return 0;
}

