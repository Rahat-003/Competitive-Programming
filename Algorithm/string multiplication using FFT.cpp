#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pi acos(-1)
typedef complex<double> cd;

void FFT(vector<cd> &a,bool invert){
	int n = a.size();
	if(n==1)	return;
	vector<cd> a0(n/2),	a1(n/2);
	for(int i = 0; 2*i<n; i++){
		a0[i] = a[2*i];
		a1[i] = a[2*i+1];
	}
	FFT(a0,invert);	FFT(a1,invert);
	double ang = 2*pi/(double)n*(invert?-1:1);
	cd w(1), wn(cos(ang),sin(ang));
	for(int i = 0; 2*i<n; i++){
		a[i] = a0[i] + w*a1[i];
		a[i+n/2] = a0[i] - w*a1[i];
		if(invert){
			a[i]/=2;
			a[i+n/2]/=2;
		}
		w*=wn;
	}
	return;
}

bool check(vector<int> &v){
	for(int i:v)	if(i)	return false;
	return true;
}

string mul(vector<int> &a,vector<int> &b){
	if(check(a) || check(b))	return "0";
	vector<cd> fa(a.begin(),a.end()),	fb(b.begin(),b.end());
	int n = 1;
	while(n<a.size() + b.size())	n*=2;
	fa.resize(n);	fb.resize(n);
	FFT(fa,false);	FFT(fb,false);
	for(int i = 0; i<fa.size(); i++)	fa[i]*=fb[i];
	FFT(fa,true);
	int tsz = a.size() + b.size() - 2;	
	string s;	
	int p,carry = 0,i,j,sz = s.size()-1;
	for(i = tsz,j = 0; i>=0; i--, j++){
		int p = round(fa[i].real());
		s.push_back( (carry + p%10)%10 + '0' );
		carry = (carry + p)/10;
	}
	while(carry>0){
		s.push_back( (carry%10) + '0');
		carry/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}

vector<int> make(string s){
	vector<int> v;
	for(int i = 0; i<s.size(); i++)	v.push_back(s[i] - '0');
	return v;
}

int main(){
int t,tc = 0;
scanf("%d",&t);
while(t--){
	string a,b;		cin>>a>>b;	
	vector<int> p,q;	string ans;
	p = make(a);	q = make(b);
	ans = mul(p,q);
	cout<<ans<<endl;
}

return 0;
}

