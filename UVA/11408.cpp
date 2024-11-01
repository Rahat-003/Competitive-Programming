#include <cstdio>
#include <vector>
using namespace std;
const int MX = 5000000+1;
int ar[MX+6];
int data[MX+3];
vector<int> prime = {2};
void sieve(){
	for(int i = 3; i*i<=MX; i+=2)	
	if(!ar[i])	{
		prime.push_back(i)	;
		for(int j = i*i; j<MX; j+=2*i)	ar[j] = 1;
	}

}


bool check(int n){
	if(n==2 || (n%2!=0 && !ar[n]) )	return true;
	int ans = 0;
	for(int i = 0; i<prime.size(); i++){
		int p = prime[i];
		if(p*p>n || (i && n%2!=0 && !ar[n]) )	break;
		if(n%p==0){
			ans+=p;
			while(n%p==0)	n/=p;
		}
	}
	if(n>1)	ans+=n;
	if(ans==2)	return true;
	if(ans%2==0)	return false;
	return !ar[ans];
}

int main(){
int t,tc = 0;
sieve();
data[2] = 1;
for(int i = 3; i<MX; i++){
	data[i] = data[i-1] + (check(i)?1:0);	
}	

int a,b;
while(1==scanf("%d",&a)){
	if(!a)	break;
	scanf("%d",&b);
	printf("%d\n",data[b]-data[a-1]);
}
/*
*/

return 0;
}

