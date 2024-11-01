#include <bits/stdc++.h>
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;

const int N=100001;

int par[N],rnk[N]; //memset(par,-1,sizeof par);

int fnd(int x){
	if(par[x]==-1) return x;
	return par[x]=fnd(par[x]);
}

bool uni(int x,int y){
	x=fnd(x);y=fnd(y);
	if(x==y) return false;
	if(rnk[x]<rnk[y]) swap(x,y);
	if(rnk[x]==rnk[y]) rnk[x]++;
	par[y]=x;
	return true;
}

main(){


return 0;
}
