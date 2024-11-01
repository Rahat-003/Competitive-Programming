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
#define mx (ll)1e6+23
ll ar[mx] = {0,0,0,0,1,3,7};
ll pat[mx]= {0,0,0,0,2,4,6};

void make(){
	ll p = 3;
	int cnt = 0;
	for(int i = 7; i<mx; i++){
		pat[i] = pat[i-1] + p;
		cnt++;
		if(cnt==2){
			p++;cnt = 0;
		}
		ar[i] = ar[i-1]+pat[i-1];
	}
}

int main(){

make();
int n;
while(cin>>n){
	if(n<3)	break;
	printf("%lld\n",ar[n]);
}



return 0;
}
