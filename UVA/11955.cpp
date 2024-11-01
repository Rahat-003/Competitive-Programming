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
string cmb(int p,int q){
	if(!q || p==q)	return "1";	
	string M = "1";
//	int p = atoi(a.c_str());
//	int q = atoi(b.c_str());
	int dif = p - q;
	if(dif<q)	swap(dif,q);
	
	for(int i = dif+1; i<=p; i++)
		M = mul(M,to_string(i));
	
	for(int i = 2; i<=q; i++)
		M = divide(M,i);
return M;		
}

void ext(string s,string &a,string &b,int &p){
	int i,j;
	for(i = 1;i<s.size();i++){
		if(s[i]=='+')	break;
		a.push_back(s[i]);
	}
	for(j = i+1; j<s.size(); j++){
		if(s[j]==')')	break;
		b.push_back(s[j]);
	}
	string t;
	for(int k = j+2;k<s.size();k++)	t.push_back(s[k]);
	
	p = atoi(t.c_str());
}

int main(){
int t,tc = 0;
scanf("%d",&t);
cin.ignore();

while(t--){
	
	string s,a,b;	int p;
	getline(cin,s);
	ext(s,a,b,p);
	vector<string> v;
	for(int i = 0;i<=p;i++)		v.push_back(cmb(p,i));
		
	printf("Case %d: ",++tc);	
	for(int i = 0;i<v.size(); i++){
		if(i)	cout<<"+";
		string d = v[i];
		d = d+"*";
		if(v[i]=="1")	d="";
		
		string x = a+"^"+to_string(p-i);
		string y = b+"^"+to_string(i);
		if(p==i)	x = "";
		if(!i)	y = "";
		if(p-i==1)	x = a;
		if(i==1)	y = b;
		
		if(y.size() && x.size())	x.push_back('*');
	cout<<d<<x<<y;
	}
cout<<endl;
v.clear();
}

return 0;
}

