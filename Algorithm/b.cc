#include <bits/stdc++.h>
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define read                     freopen("input.txt","r",stdin)
#define write                    freopen("output.txt","w",stdout)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define mx 1000003
int ar[mx];
vector<int> prime = {2};

void sieve(){
	for(int i = 3; i*i<mx; i+=2)
	if(ar[i]==0)
		for(int j = i*i; j<mx; j+=2*i)
		ar[j] = 1;
	for(int i = 3; i<mx; i+=2)
	if(ar[i]==0)
		prime.push_back(i);
}


int main(){
//read;

sieve();
cout<<prime.size()<<" HI\n";

for(int i:prime){
	if(i>100)	break;
	cout<<i<<" ";
}




return 0;
}
