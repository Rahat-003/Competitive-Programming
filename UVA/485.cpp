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

string f(int p,int q){
		string M = "1";
	if(!q || p==q)	return M;
	int dif = p - q;
	if(dif<q)	swap(dif,q);
	
	for(int i = dif+1; i<=p; i++)
		M = mul(M,to_string(i));
	
	for(int i = 2; i<=q; i++)
		M = divide(M,i);
	return M;	
}

int main(){
	

int n = 1;
puts("1");
bool fl = false;
string z;
while(fl==false){
	vector<string> v,p;
	
	for(int i = 0; i<=n/2; i++){
		string s = f(n,i);
		v.push_back(s);
		if(s.size()>60){
		fl = true;
		z = s;
		}
	}
	int k = 0;
	if(n%2==0) k = 1;
	
	for(int i = v.size()-1-k; i>=0; i--)
		p.push_back(v[i]);
	for(auto i:v)
		cout<<i<<" ";
	for(int i = 0; i<p.size();i++){
		if(i)	cout<<" ";
		cout<<p[i];
	}
	cout<<endl;

	n++;
	v.clear();
	p.clear();
}

//cout<<z<<" "<<z.size()<<endl;


return 0;
}

