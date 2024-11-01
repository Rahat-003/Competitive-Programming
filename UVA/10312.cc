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
#define mx 28
string catalan[mx]  , super_catalan[mx] = {"0", "1", "1"};

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

void mcat(){
	for(int j = 1; j<=3; j++){
	string M = "1";
	int p = 2*j;
	int q = j;
	int dif = p - q;
	if(dif<q)	swap(dif,q);

	for(int i = dif+1; i<=p; i++)
		M = mul(M,to_string(i));

	for(int i = 2; i<=q; i++)
		M = divide(M,i);
	catalan[j] = M;
	}

	for(int i = 4; i<mx; i++){
		string p = catalan[i-1];
		int q = (i*2)*(i*2-1);
		p = mul(p,to_string(q));
		p = divide(p,i);
		p = divide(p,i);
		catalan[i] = p;
	}
	for(int i = 3; i<mx; i++ )
        catalan[i] = divide(catalan[i],i+1);

	catalan[0] = catalan[1] = "1";
	catalan[2] = "2";
}

void sCat(){


        for(int i = 3; i<mx; i++){
            string p = mul("3", mul( to_string(2*i-3),super_catalan[i-1] ));
            string q = mul( to_string(i-3),super_catalan[i-2] );
            super_catalan[i] = divide(sub(p,q),i);
        }

}

int main(){
string a,b;
int n;
mcat();
sCat();
while(cin>>n){
//	string s = sub(a,b);

    string ans = sub(super_catalan[n],catalan[n-1]);
	cout<<ans<<endl;
}

return 0;
}

