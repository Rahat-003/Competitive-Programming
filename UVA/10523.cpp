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

string mul(string a,string b){
	if(a=="0" || b=="0")	return "0";
	if(a=="1")	return b;
	if(b=="1")	return a;
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

string ar[152];

void make(string s,int n){
	string ans = "1";
	ar[0] = ans;
	for(int i = 1; i<=n; i++){
		ans = mul(ans,s);
		ar[i] = ans;
	}

	return;
}


int main(){
int n,a;
while(scanf("%d %d",&n,&a)==2){
	string ans = "0";
	make(to_string(a),n);
	
	for(int i = 1; i<=n; i++ ){
		ans = sum(ans,mul( to_string(i),ar[i] ) );
	}
	cout<<ans<<endl;
	
}


return 0;
}

