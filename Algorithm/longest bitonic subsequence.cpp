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

int lis[50],lds[50];
int ar[50],n;

int fn(){
	int ans = 0;
	
	for(int i = 0; i<n; i++){
		lis[i] = lds[i] = 1;
		for(int j = 0; j<i; j++){
			if(ar[j]>ar[i])		lis[i] = max(lis[i],lis[j]+1);
			if(ar[j]<ar[i])		lds[i] = max(lds[i],lds[j]+1);
		}
		ans = max(ans,lis[i]+lds[i]-1);
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

