
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll smoke(ll full,ll c){
  if(!c || c==1)  return full;

  ll total = full;
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

ll b,c;
while(cin>>b>>c){
  ll ans = smoke(b,c);
  cout<<ans<<endl;
}





return 0;
}

