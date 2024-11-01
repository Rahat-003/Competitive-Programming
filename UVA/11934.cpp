
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

ll a,b,c,d,L;
while(cin>>a>>b>>c>>d>>L){
    if(!a && !b && !c && !d && !L)  break;
//  vector<ll> v;
  ll cnt = 0;
  for(ll i = 0;i<=L;i++){
    ll value = a*i*i + b*i + c;
    if(value%d==0)  cnt++;
  }
  cout<<cnt<<endl;
}




return 0;
}
