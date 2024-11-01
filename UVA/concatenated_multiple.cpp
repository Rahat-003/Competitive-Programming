#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 200001
int n,k,a[N],b[N];
map<LL,int>f[11];
int get(int k){int res=0;while(k)k/=10,res++;return res;}
LL g[N][11];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	  {
	  scanf("%d",&a[i]);
	  b[i]=get(a[i]);
	  LL x=a[i]%k;
	  for(int j=1;j<=10;j++)
	    x*=10ll,x%=k,f[j][x]++,g[i][j]=x;
	  }
	LL ans=0;
	for(int i=1;i<=n;i++)
	  ans+=f[b[i]][(k-a[i]%k)%k]-((g[i][b[i]]+a[i])%k==0);
	printf("%I64d\n",ans);
	return 0;
}
