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
vector<int> prime;

bool ar[mx];
int tot[mx];

void sieve(){
	ar[0] = ar[1] = 1;
	for(int i = 4; i<mx; i+=2)	ar[i] = 1;
	for(int i = 3; i*i<=mx; i+=2)	if(!ar[i])	for(int j = i*i; j<mx; j+=2*i)	ar[j] = 1;
	for(int i = 2;i<mx; i++)	if(!ar[i]){		prime.push_back(i);	 
	}
}
void make(){
	for(int i = 0; i<prime.size(); i++){
		int ans = 0;
		for(int j = 0; j<=i; j++){
		int p = prime[j],t = 0;
			ans+=p;
			for(int k = j+1; k<=i; k++){
				t+=prime[k];
			}
			if(t<mx)
			tot[t]++;
		}
		if(ans<mx)
		tot[ans]++;
	}
}



int main(){
sieve();
make();
int n;
while(1==scanf("%d",&n)){
	if(!n)	break;
	printf("%d\n",tot[n]);
}


return 0;
}

