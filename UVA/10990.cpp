
#include <cstdio>
#include <vector>
using namespace std;
#define Mx 2000003
typedef long long ll;
ll phi[Mx];
ll depth[Mx];

void totient(){
    for(ll i = 0;i<Mx; i++){
        phi[i] = i;
        if(i%2==0)  phi[i]/=2;
    }
    for(ll i = 3; i<Mx; i++){
        if(phi[i]==i){
            --phi[i];
            for(ll j = i+i; j<Mx; j+=i)    phi[j]-=phi[j]/i;
        }
    }
}

void calc(){
    depth[1] = 1;
    depth[2] = 1;
    for(ll i = 3; i<Mx; i++){
//        if(depth[i])    continue;
    ll cnt = 0;
    ll id = i;

    while(!depth[id]){
        cnt++;
        id = phi[id];
    }
    cnt+=depth[id];
    depth[i] = cnt;
    }
return;
}

int main(){
totient();
calc();


int n;
scanf("%d",&n);
while(n--){
    ll ans = 0,a,b;
    scanf("%lld %lld",&a,&b);
    for(ll i = a; i<=b; i++)
        ans+=depth[i];
    printf("%lld\n",ans);
}



return 0;
}
