#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("print.txt","w",stdout)
typedef long long ll;
using namespace std;

string mul(string a,string b){
	if(a=="0" || b=="0")	return "0";
	vector<int> v(a.size()+b.size(),0);
	int i1 = 0,i2,carry = 0;
	
	for(int i = a.size()-1; i>=0; i--){
		i2 = 0;
		carry = 0;
		for(int j = b.size()-1; j>=0; j--){
			int ans = v[i1+i2] + carry + (a[i] - '0')*(b[j]-'0');
			v[i1+i2] = ans%10;
			carry = ans/10;
			i2++;	
		}
		if(carry)	v[i1+i2]+=carry;
	i1++;
	}
	string t;
	for(int i = v.size()-1; i>=0; i--){
		if(v[i]){
			for(int j = i; j>=0; j--)
				t.push_back(v[j] + '0');
			return t;
		}
	}
}

string divide(string a,int n){
	int x = 0;
	string t;
	for(int i = 0; i<a.size(); i++){
		int ans = (10*x) + (a[i] - '0');
		if(t.size() || ans/n)	t.push_back( (ans/n) + '0' );
		x = ans%n;
	}
	return t;
}



int main(){

ll p,q;
while(2==scanf("%lld %lld",&p,&q)){
//	if(a=="0" && b=="0")	break;
	string M = "1";
//	ll p = atoi(a.c_str());
//	ll q = atoi(b.c_str());
	ll dif = p - q;
	if(dif<q)	swap(dif,q);
	
	for(ll i = dif+1; i<=p; i++)
		M = mul(M,to_string(i));
	
	for(ll i = 2; i<=q; i++)
		M = divide(M,i);
		
	printf("%lld\n",M.size());
}


return 0;
}
