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

string ar[802];

string mul(string a,string b){
	if(a=="0" || b=="0")	return "0";
	vector<int> v(a.size()+b.size(),0);
	int i1=0,i2,carry;
	for(int i = a.size() - 1; i>=0; i--){
		int x = a[i] - '0';
		i2 = 0;carry = 0;
		for(int j = b.size()-1; j>=0; j--){
			int y = b[j] - '0';
			int ans = v[i1+i2] + carry + x*y;
			v[i1+i2] = ans%10;
			carry = ans/10;
			i2++;
		}
		if(carry)	v[i1+i2]+=carry;
		i1++;
	}
	string t;
	for(int i = v.size()-1; i>=0; i--)
		if(t.size() || v[i])	t.push_back(v[i] + '0');
		return t;
}

string sum(string a,string b){
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	
	if(b.size()<a.size())	swap(a,b);
	string t;
	int carry = 0;
	
	for(int i = 0; i<a.size(); i++){
		int ans = (a[i] - '0')+(b[i] - '0') + carry;
		carry = ans/10;
		ans%=10;
		t.push_back(ans+'0');
	}
	
	for(int i = a.size(); i<b.size(); i++){
		int ans = (b[i] - '0')+carry;
		carry = ans/10;
		ans%=10;
		t.push_back(ans+'0');
	}
	if(carry)	t.push_back(carry+'0');
	
	reverse(t.begin(),t.end());
	
	for(int i = 0; i<t.size(); i++)
		if( (t[i] - '0')>0){
			t = t.substr(i);
			return t;
		}
	
}

string dp(int n){
	if(n==1)	return "0";
	if(n==2)	return "1";
	if(ar[n].size())	return ar[n];
	
	string x = sum(dp(n-1),dp(n-2));

//	ar[n] = (n-1)*(dp(n-1)+dp(n-2));
	
	ar[n] = mul(to_string(n-1),x);
	return ar[n];
}


int main(){
//write;
dp(800);
ar[0] = "0";
ar[1] = "0";
ar[2] = "1";
int n;
while(1==scanf("%d",&n)){
	if(n==-1)	break;
	cout<<ar[n]<<endl;
}


return 0;
}

