#include <cstdio>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
using namespace std;
#define pi acos(-1)
#define mx 2005
int lis[mx],lds[mx];
int ar[mx];


int main(){
int t,tc = 0;
scanf("%d",&t);
while(t--){
	int n;	scanf("%d",&n);
	for(int i = 0; i<n; i++)	scanf("%d",&ar[i]);
	
	int ans = 0;
	for(int i = n-1; i>=0; i--){
		lis[i] = 1;
		lds[i] = 1;
		for(int j = n-1; j>i; j--){
			if(ar[i]>ar[j])	lis[i] = max(lis[i],lis[j]+1);
			if(ar[i]<ar[j])	lds[i] = max(lds[i],lds[j]+1);
		}
		ans = max(ans,lis[i]+lds[i]-1);
	}
	printf("%d\n",ans);
}


return 0;
}

