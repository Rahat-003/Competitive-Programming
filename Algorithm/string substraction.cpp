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

string sub(string a,string b){
	if(b=="0")	return a;
	if(a==b)	return "0";		
	if(a.size()<b.size())	swap(a,b);
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	
	for(int i = b.size(); i<a.size(); i++ )
		b.push_back('0');
	int carry = 0;
	string t;
	for(int i = 0; i<a.size(); i++){
		int x = a[i] - '0';
		int y = (b[i] - '0') + carry;
		if(x<y){
			x+=10;	carry = 1;		
		}
		else carry = 0;
		int ans = x-y;	
			t.push_back(ans+'0');
	}
	reverse(t.begin(),t.end());
	for(int i = 0; i<t.size(); i++){
		int x = t[i] - '0';
		if(x>0 && x<10){
			t = t.substr(i);
			return t;
		}
	}
}


int main(){
string a,b;
while(cin>>a>>b){
	string s = sub(a,b);
	cout<<s<<endl;
}

return 0;
}

