#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define read                    freopen("input.txt","r",stdin)


ll gcd(ll a,ll b){
  if( b%a==0 )  return a;
  return gcd(b%a, b );
}

ll bigmod(ll n,ll p,ll m){
    if(p==0)    return 1;
    if(p==1)    return n%m;
    ll x = bigmod(n,p/2,m)%m;
    if(p%2==0)  return (x*x)%m;
    return (((x*x)%m)*(n%m))%m;
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

read;

ll b,p,m;

while(cin>>b>>p>>m){

//  ll ans = power(b,p,m);
//  ans = (ans%m + m)%m;
    cout<<bigmod(b,p,m)<<endl;
//  cout<<ans<<endl;
}






return 0;
}

