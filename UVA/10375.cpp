#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <vector>
#include <memory.h>
#include <algorithm>
#define read    	freopen("tst.txt","r",stdin)
#define write   	freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;

vector<int> up,down;

void make(int a,int b,vector<int> &v,vector<int> &w){
	int dif = a-b;
	if(dif<b)	swap(b,dif);
	
	for(int i = dif+1;i<=a;i++)
		v.push_back(i);
	for(int i = 2; i<=b; i++)
		w.push_back(i);
}


int main(){
int a,b,c,d;

while(4==scanf("%d %d %d %d",&a,&b,&c,&d)){
	
	make(a,b,up,down);
	make(c,d,down,up);

	sort(up.begin(),up.end() );
	sort(down.begin(),down.end() );

	double ans = 1.0;
	int sz = up.size()-1;
	
	if(down.size()<up.size())
		for(int i = down.size(); i<up.size(); i++)
			down.push_back(1);	
	
	for(int i = 0; i<up.size(); i++ ){
		double x = (double)up[i];
		double y = (double)down[i];	
		ans*=x;
		ans/=y;
	}
	
	if(down.size()>up.size())
		for(int i = up.size(); i<down.size(); i++){
			double y = (double)down[i];	
			ans/=y;
		}

	ans = floor(ans*100000.0 + .5)/100000.0;

	cout<<fixed<<setprecision(5)<<ans<<endl;
	up.clear();
	down.clear();
}

return 0;
}

