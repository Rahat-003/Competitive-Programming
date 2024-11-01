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

vector<string> v = {"0","1","1"};

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

void make(){
	int sz = 0;
	while(sz<=1000){
		string s = sum( v[v.size()-1], v[v.size()-2] );
		sz = s.size();
		v.push_back(s); 
	}
	
}

int main(){
make();
int n;
while(1==scanf("%d",&n)){
	if(!n)	break;
	cout<<v[2*n]<<endl;
}

return 0;
}

