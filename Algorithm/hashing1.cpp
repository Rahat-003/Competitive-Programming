#include <cstdio>
#include <iostream>
typedef long long ll;
using namespace std;

#define pi acos(-1)
#define mx 5000003
ll ar[mx];

const ll P = 26,MOD = 1e9+7;;

char s[mx];

int main(){
int t,tc = 0;
	scanf("%s",s);
	ll fwd = 0, bck = 0, ans = 0,m = 1;
	for(int i = 0;s[i]; i++){
		ll a = s[i];
		fwd = (fwd*P+a)%MOD;
		bck = (bck+m*a)%MOD;
		m = (m*P)%MOD;
        cout<<"HO "<<i<<" "<<fwd<<" "<<bck<<endl;

		if(fwd==bck){
//			cout<<0<<" to "<<i<<" is palindrome\n";
//			cout<<fwd<<" "<<bck<<endl;
//			ar[i] = ar[i/2]+1;
//			ans+=ar[i];
		}
	}
//	printf("%lld\n",ans);r

return 0;
}

