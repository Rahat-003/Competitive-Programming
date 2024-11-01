#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>&p) {return os<<'(' << p.first << ", " << p.second << ')';}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) {os << '{'; string sep;for(const T& x: v) os << sep << x, sep = ", "; return os << '}';}
void dbg_out() {cerr<<endl;}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {cerr << " " << H; dbg_out(T...); }

#ifdef SMIE
#define debug(args...) cerr << "(" << #args << "):",dbg_out(args)
#else
#define debug(args...)
#endif

#define pb			push_back
#define eb			emplace_back
#define mem(x, i)	memset(x, i, sizeof(x))
#define ff			first
#define ss			second
#define all(x)		x.begin(), x.end()
#define Q 			int t; scanf("%d", &t); for(int q=1; q<=t; q++)

typedef long long 			ll;
typedef unsigned long long 	ull;
typedef long double 		ld;
typedef pair<ll, ll> 		pi;

const double PI = acos(-1.0);
const int mod = 1e9+7;
const int mxn = 1e3+5;

int a[mxn][mxn];
int mn[mxn][mxn];
int mx[mxn][mxn];
int n, m;


int main(){
	Q{
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				scanf("%d", &a[i][j]);
				if(a[i][j] == -1) a[i][j] = 0;
			}
		}
		if((n+m-1)%2){
			printf("NO\n");
			continue;
		}
		mx[0][0] = mn[0][0] = a[0][0];
		for(int i=1; i<n; i++) mx[i][0] = mn[i][0] = mn[i-1][0]+a[i][0];
		for(int i=1; i<m; i++) mn[0][i] = mx[0][i] = mn[0][i-1]+a[0][i];
		for(int i=1; i<n; i++){
			for(int j=1; j<m; j++){
				mx[i][j] = max(mx[i-1][j], mx[i][j-1])+a[i][j];
				mn[i][j] = min(mn[i-1][j], mn[i][j-1])+a[i][j];
			}
		}
		int val = (m+n-1)/2;
		if(mn[n-1][m-1] <= val && mx[n-1][m-1] >= val){
			printf("YES\n");
		}
		else printf("NO\n");
	}
}


