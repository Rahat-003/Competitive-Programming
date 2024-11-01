
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

int t;
cin>>t;
int tc = 0;
while(t--){
  ll a;
  cin>>a;
  vector<ll> v;
  for(ll i = 2; i*i<=a;i++){
    if(a%i==0 && i*i!=a)  v.push_back(i);
    if(v.size()==2) break;
  }
  ll m = v[0], n = v[1];

  printf("Case #%d: %lld = %lld * %lld = %lld * %lld\n", ++tc, a,m,a/m,n,a/n);

}


return 0;
}
