#include <cstdio>
#include <vector>
#include <iostream>
#include <memory.h>
#define case        printf("Case %d: ",++tc);
#define read        freopen("input.txt","r",stdin)
#define write       freopen("output.txt","w",stdout)
typedef long long ll;
using namespace std;
#define mx 100002
vector<ll> v[mx];
const ll P = 132021913;

ll ar[mx],D[mx];
ll tmp[mx];


main(){
//read;
ll n;
int tc = 0,t;
for(ll i = 1; i<mx; i++)
    for(ll j = i; j<mx; j+=i)
    v[j].push_back(i);

scanf("%d",&t);

while(t--){
	memset(D,0,sizeof D);
	scanf("%lld",&n);

	for(ll i = 0; i<n; i++){
	    scanf("%lld",ar+i);
	    for(ll j:v[ar[i]])
	        D[j]+=ar[i];
	}
	
	ll ans = 0;
	for(ll i = 0; i<n; i++){
	    ll x = ar[i];
		memset(tmp,0,sizeof tmp);
	    for(ll k:v[x]) D[k]-=x,tmp[k] = 0;
	
	    for(ll j = v[x].size()-1; j>=0; j--){
	        ll y = v[x][j];
	        if(D[y]-tmp[y]==0)  continue;
	        ll p = x/y*(D[y]-tmp[y]);
	        p%=P;
	        ans = (ans+p)%P;
	        ans = (ans+P)%P;
//			cout<<x<<" "<<y<<" "<<" "
	//        cout<<y<<" "<<D[y]<<" "<<tmp[y]<<endl;
	//        cout<<"y "<<y<<" x "<<x<<" tmp[y] "<<tmp[y]<<" p "<<p<<endl;
	//        ans = (ans+p)%P;
			cout<<x<<" "<<"y "<<y<<" "<<D[y] - tmp[y]<<" lcm "<<p<<endl;
	        for(ll k:v[y]) tmp[k]+=D[y];
	    }
	}
	case;
	printf("%lld\n",ans);

}

return 0;
}

