#include <iostream>
#include <list>
using namespace std;

#define ll long long


ll phi(ll n){
    list<ll> l;
  double ans = (double) n;

  while(n%2==0){
    l.push_back(2);
    n/=2;
  }

  for(ll i = 3; i*i<=n; i+=2){
    while(n%i==0){
      l.push_back(i);
      n/=i;
    }

  }
  if(n>2) l.push_back(n);
  l.unique();

  for(auto it = l.begin(); it!=l.end(); it++ ){
    auto p = (double)*it;
    ans*=(1-1/p);
//    ans = (ans*(p-1))/p;
  }
l.clear();
  return (double)ans;
}

int main(){

//freopen("tst.txt","r",stdin);

ll n;

while(cin>>n){

/*
  ll ans = phi(n);

  cout<<ans;

  cout<<endl;

l.clear();
*/
for(ll i = 1;i<=n;i++)
    cout<<phi(i)<<" ";

}


return 0;
}

