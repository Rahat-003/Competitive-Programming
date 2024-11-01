#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <map>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define mx 2002
bool ar[mx];
map<char,int> mp;

void sieve(){
	
	for(int i = 0; i<26; i++)
		mp['a'+ i] = i+1; 
		
	for(int i = 0; i<26; i++)
		mp['A'+i] = 27+i;
	
	
	ar[0] = true;
	for(int i = 4; i<mx; i+=2)
		ar[i] = true;
		
	for(int i = 3; i*i<=mx; i+=2)
		if(!ar[i])
			for(int j = 2*i; j<mx; j+=i)
				ar[j] = true;
}

bool check(string s){
	int sum = 0;
	for(int i = 0; i<s.size(); i++){
		sum+= mp[ s[i] ];
	}
	
	return ar[sum]==false;
}

int main(){
sieve();

string s;
int t = 0;
while(cin>>s){
	if(check(s))	puts("It is a prime word.");
	else puts("It is not a prime word.");
}



return 0;
}

