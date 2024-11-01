#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>v;
ll sum(ll n){
    ll s=0;
    if(n<10) s+=n;
    while(n!=0){
        s+=n%10;
        n/=10;
    }
    return s;
}
ll sum_of_pf(ll n){
    ll s=0;
    while(n%2==0){
        s+=2;
        v.push_back(2);
        n/=2;
    }
    for(int i=3;i*i<=n;i+=2){
        while(n%i==0){
            s+=sum(i);
            v.push_back(i);
            n/=i;
        }
    }
    if(n>2){
        s+=sum(n);
        v.push_back(n);
    }
    return s;

}


int main(){
ll a;
while(cin>>a){
    for(ll i=a+1;;i++){
        v.clear();
        if(sum(i)==sum_of_pf(i) && v.size()!=1){
            cout<<i<<endl;
            break;
        }
    }
}


return 0;
}
