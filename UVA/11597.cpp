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
#define mx 402
int ar[mx];

void make(){
	for(int i = 2; i<mx; i++){
		ar[i] = i/2;
		if(i&1)	ar[i]++;
	}
}

int main(){
make();
int n,tc = 0;
while(1==scanf("%d",&n)){
	if(!n)	break;
	printf("Case %d: %d\n",++tc,ar[n]);
}


return 0;
}

