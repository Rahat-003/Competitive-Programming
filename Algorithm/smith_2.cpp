#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define ll long long
#define MAX 1000001
vector <ll> v;
ll sum(ll n){
    ll s=0;
    if(n<10) s+=n;
    else {
        while(n!=0){
            s+=n%10;
            n/=10;
        }
    }
    return s;
}
ll prime(ll n){
    ll s=0;
    while(n%2==0){
        s+=2;
        v.push_back(n);
        n/=2;
    }
    for(ll i=3;i*i<=MAX;i+=2){
        while(n%i==0){
            v.push_back(i);
          if(i<10)  s+=i;
          else s+=sum(i);
            n/=i;
        }
    }
    if(n>2){
        v.push_back(n);
        if(n<10) s+=n;
        else s+=sum(n);
    }
    return s;
}
ll check(ll n){
    for(ll i=n+1;;i++){
        v.clear();
        if(sum(i)==prime(i) && v.size()!=1){
            return i;
            break;

        }
    }
}
set<ll>vv;

int main(){
ll a,b;
while(cin>>a>>b){
        vv.clear();
        for(ll i=a-1;i<b;i++){
        //if(check(i)!=check(i+1))
            vv.insert(check(i));
           // vv.push_back(check(i));
       }

    for(auto it=vv.begin(); it!=vv.end();++it){
    cout<<*it<<" ";
}

cout<<endl;
}

return 0;
}
