#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

struct point{
	double x,y;
	bool operator < (const point &p){
		if(x!=p.x)	return x<p.x;
		return y<p.y;
	}
};
vector<point> v;

bool check(int p,int i){
	return p&(1<<i);
}
int Set(int p,int i){
	return p|=(1<<i);
}

int n;
double dist(point a,point b){
	return hypot(a.x-b.x,a.y-b.y);
}
double dp[(1<<16) + 5];

double fn(int mask,int pos){
	if(mask==(1<<n)-1)	return 0;

	if(dp[mask]!=-1)    return dp[mask];

    double ans = 1000000.0;

	for(int i = pos; i<n; i++){
        if(!check(mask,i)){

            for(int j = 0; j<n; j++){
                if(i!=j && !check(mask,j)){
                    ans = min( ans , dist(v[i], v[j] ) + fn( Set( Set(mask,j), i ),i+1 ) );
                }
            }
        }
	}

    dp[mask] = ans;

	return ans;
}



int main(){
//read;
int t,tc = 0;
while(1==scanf("%d",&n)){
	if(!n)	break;
	n*=2;
	for(int i = 0; i<(1<<n)+3; i++) dp[i] = -1;
	v = vector<point>(n);
	for(int i = 0; i<n; i++){
		string s;
		cin>>s;
		scanf("%lf%lf",&v[i].x,&v[i].y);
	}

	double ans = fn(0,0);
    case;
    printf("%.2f\n",ans);
}

return 0;
}

