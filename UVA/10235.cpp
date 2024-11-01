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

#define mx (int)1e6+3
bool ar[mx];
void sieve(){
	ar[0] = ar[1] = 1;
	for(int i = 4; i<mx; i+=2)	ar[i] = 1;
	for(int i = 3; i*i<=mx; i+=2)	if(!ar[i])	for(int j = i*i; j<mx; j+=2*i)	ar[j] = 1;
}

int main(){
//	read;
sieve();
int n;
while(cin>>n){
	string s = to_string(n)	;
	reverse(s.begin(),s.end());
	int p = atoi(s.c_str());
	if(!ar[n] && !ar[p] && n!=p){
		printf("%d is emirp.\n",n);
	}
	else if(!ar[n]){
		printf("%d is prime.\n",n);
	}
	else printf("%d is not prime.\n",n);
	
}


return 0;
}

