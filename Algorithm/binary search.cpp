
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ar[100];

ll binsearch(ll l, ll h,ll x){
    ll m= (l+h)/2;
    if(ar[m]==x) return m;

		if(x<ar[0])	return 0;

	if(l==h){
		if(ar[h]>x)	return h;
		return h+1;
	}
	
	if(h-l==1){
		if(ar[l]>x)	return l;
		if(ar[h]>x)	return h;
	}

    if(x>ar[m]) return binsearch(m+1,h,x);
    else return binsearch(l,m-1,x);
}

int main(){
int n;
cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    sort(ar,ar+n);
    int x;
while( cin>>x)
    cout<<binsearch(0,n-1,x)<<endl;




return 0;
}
