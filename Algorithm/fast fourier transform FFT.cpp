#include <bits/stdc++.h>
using namespace std;

#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
#define pi acos(-1)

typedef complex<double> cd;

void FFT(vector<cd> &a, bool inverse){
	int n = a.size();
	if(n==1)	return;
	
	double ang = 2*pi/(double)n*(inverse?-1:1);
	cd w(1),wn(cos(ang),sin(ang));
	
	vector<cd> a0(n/2),a1(n/2);
	for(int i = 0; 2*i<n; i++){
		a0[i] = a[2*i];
		a1[i] = a[2*i+1];
	}
	
	FFT(a0,inverse); 
	FFT(a1,inverse);
	
	for(int i = 0; 2*i<n; i++){
		a[i] = a0[i] + w*a1[i];
		a[i+n/2] = a0[i] - w*a1[i];
		
		if(inverse){
			a[i]/=2;
			a[i+n/2]/=2;
		}
		w*=wn;
	}
}

vector<int> multiply(vector<int> &a, vector<int> &b){
	vector<cd> fa(a.begin(),a.end()),	fb(b.begin(), b.end());
	
	int tsz = a.size() + b.size();
	int n = 1;
	while(n<tsz)	n<<=1;
	
	fa.resize(n);	fb.resize(n);
	FFT(fa,false);		FFT(fb,false);
	
	for(int i = 0; i<fa.size(); i++)	fa[i]*=fb[i];
	
	FFT(fa,true);
	
	vector<int> result(n);
	int x;
	for(int i = 0; i<fa.size(); i++){
		result[i] = round(fa[i].real());
		if(result[i])	x = i;
	}	
	result.resize(x+1);
	
	return result;
}	

int main(){

int t,tc = 0;

vector<int> u = {3,2,4},	v = {5,1,2},res;
res = multiply(u,v);

for(int i = 0; i<res.size(); i++)	cout<<res[i]<<" ";
cout<<endl;

return 0;
}

