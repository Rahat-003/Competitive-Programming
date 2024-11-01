#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("print.txt","w",stdout)
#define mx (int)1e7+2
typedef long long ll;
using namespace std;
int ar[mx];

void cal(){
	int ans;	double x = 1;
	for(int i = 1; i<mx; i++){
		x += log10(i);
		ar[i] = (int)x;
	}
}


int main(){
int t;
cal();
scanf("%d",&t);
while(t--){
	int a;
	scanf("%d",&a);
	printf("%d\n",ar[a]);
}




return 0;
}

