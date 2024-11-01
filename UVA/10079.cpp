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




int main(){
ll n;
while(1==scanf("%lld",&n)){
	if(n<0)	break;	
	ll p = n;
//	ll ans;
	if(n%2==0){
		n/=2;	n*=(p+1);	n+=1;
		printf("%lld\n",n);
	}
	else{
		p+=1;	p/=2; p*=n;	p+=1;
		printf("%lld\n",p);
	}
	
}


return 0;
}

