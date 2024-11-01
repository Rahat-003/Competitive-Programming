#include <cstdio>
#include <cmath>
#include <vector>
#include <iomanip>
#include <iostream>
#include <bits/stdc++.h>
#include <memory.h>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("print.txt","w",stdout)
typedef long long ll;
using namespace std;
vector<int> prime;
#define mx (int)1e4+5
bool ar[mx];
int tot[mx];

void sieve(){
	prime.push_back(2);
	for(int i = 3; i*i<=mx; i+=2)
		if(!ar[i])	
			for(int j = i*i; j<mx; j+=2*i)
				ar[j] = true;
	
	for(int i = 3; i<mx; i+=2)
		if(!ar[i])	prime.push_back(i);
}
bool isP(int n){

	for(auto i:prime){
		if(i*i>n)	break;
		if(n%i==0)	return false;
	}
	return true;
}

void cal(){
	
	for(int i = 0; i<=10001; i++){
		int k = i*i+i+41;
	if(i)	tot[i] = tot[i-1];
		if(isP(k))	tot[i]++;
	}
	
}

int main(){
sieve();
cal();
int a,b;
while(2==scanf("%d %d",&a,&b)){
	if(a>b)	swap(a,b);
	double x,y;
	x = (double)tot[b] - (double)tot[a-1];
	y = (double)(b-a+1);
	double ans = (x/y)*100;
	ans = floor(ans*100.0 + .5)/100.00;
	printf("%.2lf\n",ans);
//	printf("%.2lf %lf\n",ans,ans);
//	cout<<fixed<<setprecision(2)<<(x/y)*100<<endl;
}


return 0;
}

