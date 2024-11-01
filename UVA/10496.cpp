#include <cstdio>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

typedef pair<int,int> pp;
vector<pp> v;
int dist[22][22];
int dp[15][(1<<11)];
int n;

int check(int p,int i){
	return p&=(1<<i);
}
int Set(int p,int i){
	return p|=(1<<i);
}
int reset(int p,int i){
	return p&=~(1<<i);
}
int cnt = 0;

int fn(int cur,int mask){
	if( mask==(1<<(n+1))-1 )	return dist[cur][0];
	if(dp[cur][mask]!=-1)	return dp[cur][mask];
	int ans = 1e7;
	cnt++;
	for(int i = 0; i<=n; i++)
		if(i!=cur && !check(mask,i)){
			mask = Set(mask,cur);
			ans = min(ans, dist[cur][i] + fn(i,Set(mask,i)) );
			mask = reset(mask,cur);
		}
	
	return dp[cur][mask] = ans;
}

int main(){

int t,tc = 0;

scanf("%d",&t);

while(t--){
	int r,c,a,b;	scanf("%d%d",&r,&c);
	scanf("%d%d",&a,&b);
	v.push_back({a,b});
	scanf("%d",&n);
	for(int i = 0; i<n; i++){
		scanf("%d%d",&a,&b);
		v.push_back({a,b});
	}
	memset(dp,-1,sizeof dp);
	for(int i = 0; i<=n; i++){
		for(int j = 0; j<=n; j++){
			int d = abs(v[i].first-v[j].first) + abs(v[i].second - v[j].second);
			dist[i][j] = d;
		}
	}	
	int ans = fn(0,0);
	printf("The shortest path has length %d\n",ans);
	v.clear();
	printf("%d\n",cnt);
}

return 0;
}

