#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;

ll sum(ll n){
    ll s=0;
while(n!=0){
    s+=(n%10);
    n/=10;
}
return s;
}

ll prime(ll n){
    int s=0;
while(n%2==0){
    v.push_back(2);
    s+=2;
    n/=2;
}
for(ll i=3;i*i<=n;i+=2){
    while(n%i==0){
        v.push_back(i);
        if(i<10)
            s+=i;
        else
            s+=sum(i);
        n/=i;
    }
}
if(n>2) v.push_back(n);
if(n>2&&n<10)
    s+=n;
if(n>=10)
    s+=sum(n);
return s;
}

int main(){
ll t;
cin>>t;
while(t--){
ll n;
cin>>n;
    for(ll i=n+1;;i++){
            v.clear();
        if(sum(i)==prime(i) && v.size()!=1){
            cout<<i<<endl;
                break;
        }

}
}

return 0;
}
