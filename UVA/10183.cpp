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

string sum(string a,string b){
    if(a.size()>b.size())
        swap(a,b);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int ans,carry=0;
    string s;
    for(int i=0;i<a.size();i++){
        ans= (a[i]- '0') + (b[i] -'0') +carry;
        carry=ans/10;
        s.push_back(ans%10 + '0');
    }
    for(int i=a.size();i<b.size();i++){
        ans= (b[i] -'0') +carry;
        carry=ans/10;
        s.push_back(ans%10 + '0');
    }
    if(carry)s.push_back(carry + '0');
    reverse(s.begin(),s.end());
    return s;
}
vector<string> v;

int small(string a,string b){
	if(a==b)	return 2;
	if(a.size()<b.size())	return 1;
	if(a.size()>b.size())	return 3;
	for(int i = 0; i<a.size(); i++)
	{
		int x = a[i] - '0',  y = b[i] - '0';
		if(x==y)	continue;
		if(x<y)	return 1;
		return 3;
	}
}

int main(){
//read;
v.push_back("0");
v.push_back("1");

int sz = v[v.size()-1].size();

while(sz<=100){
	v.push_back(sum( v[v.size()-1], v[v.size()-2]) );	
	sz = v[v.size()-1].size();
}
v[0] = "";
v[1] = "0";
v[2] = "1";
string a,b;

while(cin>>a>>b){
	if(a=="0" && b=="0")	break;
	int x,y;
	bool f1 = false,f2 = false;
	
	int z = 0;
	if(a=="0")	z-=1;
	
	for(int i = 0;i<v.size(); i++){
		string s = v[i];
		if(s==a){
			x = i;
			f1 = true;
		}
		if(s==b){
			y = i;
			f2 = true;
		break;
		}
	}
	
	if(f1 && f2){
		printf("%d\n",z+y-x+1);
		continue;
	}
//	bool fx = false;
	for(int i = 0; i<v.size(); i++){
		string s = v[i];
		if(f1)	break;
		
		if(small(s,a)==3){
			x = i;	break;
		}
	}
	for(int i = 0; i<v.size(); i++){
		if(f2)	break;
		string s = v[i];
		if(small(s,b)==3){
			y = i;	break;
		}
	}

	if(!f1 && !f2){
		cout<<y-x+z<<endl;	continue;
	}
	
	if(!f1){
		cout<<y-x+1+z<<endl;
	}
	else cout<<y-x+z<<endl;
	
	
}
/*
for(auto i:v)
cout<<i<<endl;
*/


	
return 0;
}

