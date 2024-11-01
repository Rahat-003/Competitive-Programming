
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll soda(ll full,ll c){
  if(!c || c==1)  return full;

  ll total = 0;
  ll extra = 0;// = full%3;
  ll faka;

  while(true){
    if(full<c)  break;

    total+= full/c;
    extra = full%c;
    full/=c;
    full+=extra;
  }
  //cout<<"faka "<<extra<<endl;
  return total;

}


int main(){

int t;
cin>>t;
while(t--){

ll b,d,c;
cin>>b>>d>>c;
    b+=d;
  ll ans = soda(b,c);
  cout<<ans<<endl;
}





return 0;
}


