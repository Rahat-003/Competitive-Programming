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
#define mx 1002
string ar[10];
string cube[mx];

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

string sum(string a, string b){
	if(a=="0")	return b;
	if(b=="0")	return a;
    if(a.size()>b.size())
        swap(a,b);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int c=0,ans;
    string ss;
    ss.clear();
    for(int i=0;i<a.size();i++){
        ans=(a[i]-'0')+(b[i]-'0')+c;
        c=ans/10;
        ss.push_back((ans%10)+'0');
    }
    for(int i=a.size();i<b.size();++i){
         ans=(b[i]-'0')+c;
        c=ans/10;
        ss.push_back((ans%10)+'0');
    }
if(c) ss.push_back(c+'0');
reverse(ss.begin(),ss.end());
return ss;
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
void make(string s){
	string ans = "1";
	for(int i = 1; i<=6; i++){
		ans = mul(ans,s);
		ar[i] = ans;
	}
}
void each(int n){
	///	Pólya enumeration theorem
	///	( n^6 + 3*n^4 + 12*n^3 + 8*n^2)/24 ;
	
	make(to_string(n));
	string ans = "0";
	ans = sum(ans,ar[6]);
	ans = sum(ans,mul( "3",ar[4]));
	ans = sum(ans,mul("12",ar[3]));
	ans = sum(ans,mul( "8",ar[2]));
	cube[n] = divide(ans,24);
}

void go(){
	cube[1] = "1";
	cube[2] = "10";
	for(int i = 3; i<mx; i++)	each(i);
	return;
}

int main(){
go();
int n;
while(1==scanf("%d",&n)){
	if(!n)	break;
	cout<<cube[n]<<endl;
}


return 0;
}

