#include <bits/stdc++.h>
#define case        printf("Case %d:",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)


ll mod(ll n, ll p, ll m){
    if(p==0)    return 1;
    if(p==1)    return n%m;

    if(p%2==0){
        ll x = mod(n,p/2,m);
        x%=m;
        return (x*x)%m;
    }
    else{
        ll y = mod(n,p-1,m);
        return ((n%m)*(y%m))%m;
    }
}

ll check(ll b,ll m,ll a){
    if(a==1)    return 0;
    unordered_map<ll,ll> mp;

    ll n = (ll)sqrt(m) + 1;
    for(ll i = n; i>=1; i--){
        ll p = mod(b,i*n,m);
        mp[p] = i;
    }

    for(ll j = 0; j<n; j++){
        ll p = (mod(b,j,m)*a)%m;
        if(mp[p]){
            ll k = mp[p]*n-j;
            if(k<m) return k;
        }
    }
    return -1;
}


int main(){
int t,tc = 0;
ll b,p,m,ans;
while(cin>>b>>m>>ans){
    p = check(b,m,ans);
    cout<<p<<endl;
}



return 0;
}
