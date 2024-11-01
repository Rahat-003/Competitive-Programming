

#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;

ll factor(ll n){
    unordered_map<ll,ll> mp;

    while(n%2==0 && n>1){
        mp[2]++;
        n/=2;
    }

    for(ll i = 3; i*i<=n; i+=2){
    while(n%i==0 && n>1){
        mp[i]++;
        n/=i;
        }
    }
    if(n>1) mp[n]++;
    ll ans;
    bool f = false;
    ll sz = mp.size();
    ll Min = (ll)2e7;

    for(auto i:mp){
        Min = min(Min,i.second);
    }
    vector<ll> v;
    for(auto i:mp){
        if(i.second==Min)   v.push_back(i.first);
    }
    if(v.size()==sz)    return Min;
    ans = Min;
    bool flag1 = false,flag2 = false;

    for(auto i:mp){
        ll x = i.first;
        ll y = i.second;
        if(y%sz==0) continue;
        else flag1 = true;

    }

    for(auto i:mp){
        ll x = i.first;
        ll y = i.second;
        if(y>Min){
            ll extra = (y-Min);
        if(extra%Min==0)   continue;
        else flag2 = true;;
        }
    }

    if(flag1 && flag2)  return 1;
    if(!flag1 && !flag2){
        if(sz>Min)  return sz;
        return Min;
    }

    if(!flag1)  return sz;
    if(!flag2)  return Min;
}


int main(){
//freopen("tst.txt","r",stdin);

ll n;

while(1==scanf("%lld",&n)){
    if(n==0)    break;

    bool fl = false;
    if(n<0){
        n = abs(n);
        fl = true;
    }

    ll ans = factor(n);
    if(!fl)
    printf("%lld\n",ans);
    else{
        if(ans&1)
            printf("%lld\n",ans);
        else {
            while(ans%2==0){
                ans/=2;
            }
            printf("%lld\n",ans);
        };
    }
}



return 0;
}
