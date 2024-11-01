#include <bits/stdc++.h>
using namespace std;

#include <vector>

typedef long long ll;

ll f(ll n,ll p,ll m){
    if(n==0)    return 0;
    if(p==1)    return n%m;
    if(p==0)    return 1%m;
    if(p%2==0){
        ll x = f(n,p/2,m);
        return (x*x)%m;
    }
    else {
        ll x = f(n,p-1,m);
        return ((n%m)*x)%m;
    }
}

string ms(ll n){
    string s = to_string(n);
    string sp(3-s.size(),'0');
    sp.append(s);
    return sp;
}



int main(){
//    freopen("tst.txt","r",stdin);
ll n,m,p;
int t;
scanf("%d",&t);
while(t--){
    scanf("%lld %lld",&n,&p);
    double l = p*log10((double)n);

    l = l - (ll)l;
//    cout<<l<<endl;
    double q = pow(10,l)*100;
//    cout<<q<<endl;
    ll lead = q;
    ll trail = f(n,p,1000);
    string sp = ms(trail);
    cout<<lead<<"..."<<sp<<endl;
//    printf("%lld...%s%lld\n",lead,sp.c_str(),trail);

}


return 0;
}
