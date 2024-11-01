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
#define mx 4294967296
vector<ll> v = {0,1,1}, fib = {0,1,2};

void make(){
	ll x = 0;
	int id = 0;
	while(id<=50){
		id++;
		x = v[v.size()-1] + v[v.size()-2];
//		if(fib[fib.size()-1]>mx)	break;
		v.push_back(x);
		fib.push_back( fib[fib.size()-1] + x );
	}
	
}


int main(){

make();

ll n;
while(1==scanf("%lld",&n)){
	
	if(n==-1)	break;
	if(n==0){
		puts("0 1");	continue;
	}
	cout<<fib[n]<<" "<<fib[n]+fib[n-1]+1<<endl;
}


return 0;
}

