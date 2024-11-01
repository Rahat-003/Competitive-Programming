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


int fn(int a,int b){
	if(a%b==0)	return a/b;
	return 1+a/b;
}

int main(){
int t,tc = 0;
scanf("%d",&t);
int n,x,y,d;
while(t--){
	scanf("%d%d%d%d",&n,&x,&y,&d);
	int dif = abs(x-y);
	if(dif%d==0)	printf("%d\n",dif/d);
	else{
		int f,b;
		if( (y-1)%d!=0 && (n-y)%d!=0 )	puts("-1");
		else{
			int ans = 1e9;
			int p = ans,q = ans;
			if((y-1)%d==0 ) p = (y-1)/d;
			if( (n-y)%d==0 )	q = (n-y)/d;
			ans = min( p + fn(x-1,d), q + fn(n-x,d) );
			printf("%d\n",ans);
		}
		
	}
}


return 0;
}

