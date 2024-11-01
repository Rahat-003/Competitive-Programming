#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define mx (int)1e4+3

int main(){
int n;

while(1==scanf("%d",&n)){
	if(!n)	break;
	int ans = 0,t = 0;
	
	for(int i = 0; i<n; i++){
		int a;
		scanf("%d",&a);
		t+=a;
		ans = max(ans,t);
		if(t<0)	t = 0;
	}
	if(ans>0)	printf("The maximum winning streak is %d.\n",ans);
	else puts("Losing streak.");
}


return 0;
}

