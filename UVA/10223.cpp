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
string ar[25];
void make(){
	
	for(int j = 1; j<25; j++){
	string M = "1";	
	int p = 2*j;
	int q = j;
	int dif = p - q;
	if(dif<q)	swap(dif,q);
	
	for(int i = dif+1; i<=p; i++)
		M = mul(M,to_string(i));
	
	for(int i = 2; i<=q; i++)
		M = divide(M,i);
	
		ar[j] = divide(M,j+1);
	}	
}

int cmp(string a,string b){
	if(a==b)	return 2;
	if(a.size()<b.size())	return 1;
	if(a.size()>b.size())	return 3;
	
	for(int i = 0; i<a.size(); i++){
		int x = a[i] - '0';
		int y = b[i] - '0';
		if(x==y)	continue;
		if(x<y)	return 1;
		return 3;
	}
}

int main(){

string a;int b;
make();
/*
for(int i = 1;i<25; i++){
	cout<<ar[i]<<" \n";
}
*/
string s;
while(cin>>s){
	if(s=="0"){
		puts("0");
		continue;
	}
	int id = -1;
	bool fl = false;
	for(int i = 1; i<25; i++){
		if(ar[i]==s){
			cout<<i<<endl;
			fl = true;
			break;
		}
	}
	if(fl) continue;
	
	for(int i = 1; i<25; i++){
		if(cmp(s,ar[i])==1){
			id = i;
			break;
		}
	}
	cout<<id<<endl;
}

return 0;
}

