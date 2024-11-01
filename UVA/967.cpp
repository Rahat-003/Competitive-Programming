#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <memory.h>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("print.txt","w",stdout)
typedef long long ll;
using namespace std;
#define mx (int)1e6+3
vector<int> prime;
bool ar[mx];
int tot[mx];

bool circular(int a){
	if(a==2)	return true;
	if(a%2==0)	return false;
	if(ar[a])	return false;
	string s = to_string(a);
	for(int i = 0; i<s.size(); i++){
		string p,q;
		int x = s[i] - '0';
		if(x%2==0)	return false;
		p = s.substr(i);
		q = s.substr(0,i);
		p.append(q);
		int F = atoi(p.c_str());
		if(F%2==0)	return false;
		if(ar[F])	return false;
	}
	return true;
}

void sieve(){
	ar[0] = ar[1] = true;
	prime.push_back(2);
	for(int i = 3; i*i<=mx; i+=2){
		if(!ar[i])
			for(int j = i*i; j<mx; j+=2*i)
				ar[j] = true;
	}/*
	for(int i = 3; i<mx; i+=2)
		if(!ar[i])	prime.push_back(i);*/
}

void calc(){
	for(int i = 2; i<mx; i++){
		tot[i] = tot[i-1];
	if(circular(i))	tot[i]++;
	}
}

int main(){
	sieve();
	calc();
int n;

while(1==scanf("%d",&n)){
	if(n==-1)	break;
	int m;
	scanf("%d",&m);
	int ans = tot[m]-tot[n-1];
	if(!ans) puts("No Circular Primes.");
	else if(ans==1)	puts("1 Circular Prime.");
	else printf("%d Circular Primes.\n",ans);
}




return 0;
}

