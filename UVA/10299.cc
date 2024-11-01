#include <cstdio>
#include <cmath>
#include <vector>
typedef long long ll;
using namespace std;
#define mx 32000
bool ar[mx];
vector<int> prime;

void sieve(){
	prime.push_back(2);
	for(int i = 3; i*i<=mx; i+=2){
		if(!ar[i]){
			for(int j = i*i; j<mx; j+=2*i)
			ar[j] = true;
		}
	}
	for(int i = 3; i<mx; i+=2){
		if(!ar[i])
			prime.push_back(i);
	}
}

int phi(int n){
	if(n==1)	return 0;
	
	int x = n;
	
	for(int i = 0 ; i<prime.size(); i++){
		int  p = prime[i];
		if(p>n)	break;
		if(n%p==0){
			while(n%p==0)	n/=p;
			x-=x/p;
		}
	}
	if(n>1)	x-=x/n;
	return x;
}

int main(){
//	freopen("tst.txt","r",stdin);
sieve();

int n;
while(1==scanf("%d",&n)){
	if(!n)	break;
	
	int ans = phi(n);
	printf("%d\n",ans);
}



  return 0;
}

