#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
map<string,int> mp;

vector<string> v = {"0","1","2"};

int cmp(string a,string b){
	if(a==b)	return 2;
	if(a.size()<b.size())	return 1;
	if(a.size()>b.size())	return 2;
	for(int i = 0; i<a.size(); i++){
		int x = a[i] - '0';
		int y = b[i] - '0';
		if(x==y)	continue;
		if(x<y)	return 1;
		return 3;
	}
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

void make(){
	int sz = 0;
	while(sz<=100){
		int l = v.size();
		string x = sum(v[l-1],v[l-2]);
		v.push_back(x);
		sz = x.size();
	}
	for(int i = 0; i<v.size(); i++)
		mp[v[i]] = i;
}

string check(string s){
	int i;
	for( i = 1;i<v.size(); i++){
		int fl = cmp(v[i],s);
		if(fl==2)	return v[i];
		if(fl==3)	return v[i-1];
	}
	return v[i-1];
}

void f(string s){
	vector<string> id;
	string t;
	while(s!="0"){
		string p = check(s);
		s = sub(s,p);
		id.push_back(p);
	}
	int sz = mp[id[0]];
	for(int i = 0; i<sz; i++)
		t.push_back('0');
	
	for(int i = 0;i<id.size(); i++){
		string x = id[i];
		t[ sz-mp[x] ] = '1';
	}
	cout<<t<<endl;
	id.clear();
}

int main(){
//	read;
	
make();
int p;
string s,t;
bool fl = false;
while(cin>>s>>t){
	s.push_back('0');
	t.push_back('0');
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	string s1,s2, ss;
	s1 = s2 = "0";
	for(int i = 1; i<s.size(); i++){
		int x = s[i] - '0';
		if(!x)	continue;
		s1 = sum(s1,v[i]);
	}
	for(int i = 1; i<t.size(); i++){
		int x = t[i] - '0';
		if(!x)	continue;
		s2 = sum(s2,v[i]);
	}
	string add = sum(s1,s2);
	if(fl)	cout<<'\n';
	f(add);
	fl = true;
}

return 0;
}

