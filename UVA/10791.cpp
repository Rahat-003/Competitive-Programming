
#include <cstdio>
#include <unordered_map>
using namespace std;

typedef long long ll;

ll factor(ll n,unordered_map<ll,ll> &v){
    if(n%2==0)
        v[2] = 1;

    while(n%2==0 && n>1){
        v[2]*=2;
        n/=2;
    }
    for(ll i = 3; i*i<=n; i+=2){
        if(n%i==0 && n) v[i] = 1;

        while(n%i==0 && n>1){
            v[i]*=i;
            n/=i;
        }
    }
    if(n>1) v[n] = n;

    ll ans = 0,cnt = 0;
    for(auto i:v){
        cnt++;
        ll x = i.first;
        ll y = i.second;
        ll z = 1;
        ans+=y;
        /*
        for(ll j = 0; j<y; j++){
            z*=x;
        }
        ans+=z;
        */
    }
    if(cnt==1)  return ans+1;
    return ans;
}

int main(){
ll n;
int tc = 0;

while(scanf("%lld",&n)==1){
    if(n==0)    break;
    printf("Case %d: ",++tc);

    if(n==1){
        printf("%lld\n",n+1);
        continue;
    }

    unordered_map<ll,ll> mp;
    ll  ans = factor(n,mp);

    printf("%lld\n",ans);
mp.clear();

}


return 0;
}
