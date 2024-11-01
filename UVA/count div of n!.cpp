#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fact(ll a){
    if(a==0)
        return 1;
    else{
    ll ans;
    if(a==1)
        return 1;
    ans=a*fact(a-1);
    return ans;
    }
}
ll pf(ll a){
    set<ll> s;
    ll n=fact(a);
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            s.insert(i);
            s.insert(n/i);
        }
    }
    return s.size();

}

int main(){
ll a;
cin>>a;
cout<<pf(a);
return 0;
}
