#include <bits/stdc++.h>
using namespace std;

#define mx 1503
string ar[mx], tot[mx];

string sum(string a,string b){
    if(a.size()>b.size())
        swap(a,b);
        string ss;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int carry =0;
    for(int i=0;i<a.size();i++){
        int ans=(a[i]-'0')+ (b[i]-'0') + carry;
        carry=ans/10;
    ss.push_back(ans%10+'0');
    }
    for(int i=a.size();i<b.size();i++){
        int ans= (b[i]-'0') + carry;
        carry=ans/10;
    ss.push_back(ans%10+'0');
    }
    if(carry) ss.push_back(carry+'0');
    reverse(ss.begin(),ss.end());
    return ss;
}

void fib(){
 ar[0]="0",ar[1]="1";
 string a="0",b="1",c;
 tot[1] = "0"; tot[2] = "1";
 
 for(int i=2;i<mx;i++){
    c=sum(a,b);
    a=b;
    b=c;
    ar[i]=b;
    tot[i] = sum(tot[i-1],ar[i]);
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

bool is2(string s){
	int x = (s[s.size()-1] - '0');
	return x%2==0;
}

int main(){
fib();
int a,tc = 0;

while(cin>>a){
	if(!a)	break;
	printf("Set %d:\n",++tc);
	
	if(a==1){
		puts("0");		
		continue;
	}
	string n = ar[a];
	if(!is2(n)){
		n = sum(n,"1");
	}
	n = divide(n,2);
	string ans = sum(tot[a-1],n);
	printf("%s\n",ans.c_str());
}

return 0;
}
