#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d:",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
#define mx 2000000000
vector<ll> v,ar = {2,3,5,7};
set<ll> s;

void fn(ll id,ll w){
	if(id==ar.size() || w>mx)	return;
	s.insert(w);
	
	for(ll i = id; i<ar.size(); i++){
		ll x = ar[i];
		if(x<=mx/w)		fn(i,w*x);
		else return;
	}
}

int main(){
int t,tc = 0;

fn(0,1);
v = vector<ll> (s.begin(),s.end());
int n;

while(1==scanf("%d",&n)){
	if(!n)	break;
	string pos = "th";
	if(n%10>=1 && n%10<=3 && (n%100<10 || n%100>20 )) {
		if(n%10==1)			pos = "st";
		else if(n%10==2)	pos = "nd";
		else 				pos = "rd";
	}
	
	printf("The %d%s humble number is %lld.\n",n,pos.c_str(),v[n-1]);
}



return 0;
}

