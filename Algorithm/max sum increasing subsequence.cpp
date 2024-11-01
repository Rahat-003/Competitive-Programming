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

int ar[102],n;
int L[102];

int fn(){
	int ans = 0;
	for(int i = 0; i<n; i++){
		int x = ar[i];
		for(int j = 0; j<i; j++){
			if( ar[j]<ar[i] )	x+=ar[j];
		}
		ans = max(ans,x);
	}
	return ans;
}

int main(){
int t,tc = 0;
cin>>n;
for(int i = 0; i<n; i++)	cin>>ar[i];

int ans = fn();
cout<<ans<<endl;

return 0;
}

