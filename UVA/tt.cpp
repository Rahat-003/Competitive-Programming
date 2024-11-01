#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

ll ar[200];

ll fn(ll a){
	if(a==179)	return 360;
	if(a>=180)	return -1;
	ll ans;
	
		
	for(ll i = 3;  ; i++){
		if(180%i==0){
			ll ang = 180/i;
			if(a%ang==0 && a/ang<=i-2){
				ans = i;
				ar[a] = i;
				return ans;
			}
		}
	}	
	
	
}

int main(){
int t,tc = 0;

scanf("%d",&t);
while(t--){
	ll a;
	scanf("%d",&a);
	printf("%lld\n",fn(a));
}

return 0;
}

