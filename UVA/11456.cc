#include <cstdio>
#include <vector>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
using namespace std;
#define mx 2003
vector<int> ar;

int lis[mx],lds[mx],L1[mx],L2[mx];

int bs(int s,int len){
	int l = 0,h = len,m;
	for(int i = 0; i<50; i++){
		m = (l+h)/2;
		if(l==h)	break;
		if(ar[L1[m]]>=s)	h = m;
		else l = m+1;
	}
	return m;
}

int bs2(int s,int len){
	int l = 0,h = len,m,i;
	for( i = 0; i<50; i++){
		m = (l+h)/2;
		if(l==h)	break;
		if( ar[L2[m]]>s )	l = m+1;
		else h = m;
	}
	return m;
}

int fn(int n){
	if(n==1)	return 1;
	if(!n)	return 0;
	int len1 = 0,len2 = 0;
	L1[0] = L2[0] = 0;
	lis[0] = lds[0] = 1;
	
	int ans = 0;
	for(int i = 1; i<ar.size(); i++){
		if(ar[i]>ar[L1[len1]]){
			L1[++len1] = i;
			lis[i] = len1+1;
		}
		else if(ar[L1[0]]>ar[i]){
			L1[0] = i;
			lis[i] = 1;
		}
		else{
			int id = bs(ar[i],len1);	L1[id] = i;
			lis[i] = id+1;
		}
		
		if(ar[i]<ar[L2[len2]]){
			L2[++len2] = i;
			lds[i] = len2+1;
		}
		else if(ar[L2[0]]<ar[i]){
			L2[0] = i;
			lds[i] = 1;
		}
		else{
			int id = bs2(ar[i],len2);	L2[id] = i;
			lds[i] = id+1;
		}
		
		ans = max(ans,lis[i]+lds[i]-1);
	}
	
	return ans;
}

int main(){
int t,tc = 0;
scanf("%d",&t);

while(t--){
	int n;
	scanf("%d",&n);
	ar = vector<int> (n);
	for(int i = n-1; i>=0; i--)	scanf("%d",&ar[i]);
	int ans = fn(n);
	printf("%d\n",ans);
	ar.clear();
}


return 0;
}

