#pragma                         GCC optimize("O3","unroll-loops")
#include                        <bits/stdc++.h>
#include                        <ext/pb_ds/assoc_container.hpp>
#define lb                      lower_bound
#define ub                      upper_bound
#define fe(x)                   (*(x.begin()))
#define le(x)                   (*(x.rbegin()))
#define pb                      push_back
#define load(node,n)            bool operator < (const node &n) const
#define fbo(x,id)               (*(x.find_by_order(id)))
#define ook(y)                  order_of_key(y)
#define all(x)                  (x).begin(),(x).end()
#define si(a)                   scanf("%d",&a)
#define sii(a,b)                scanf("%d %d",&a,&b)
#define siii(a,b,c)             scanf("%d %d %d",&a,&b,&c)
#define sl(a)                   scanf("%lld",&a)
#define sll(a,b)                scanf("%lld %lld",&a,&b)
#define slll(a,b,c)             scanf("%lld %lld %lld",&a,&b,&c)
#define rep(i,a,b)              for(ll i = a; i<=b;  i++)
#define un(x)                   x.erase(unique(all(x)), x.end())
#define TT                      long long TC;  scanf("%lld",&TC);  for(ll tc = 1; tc<=TC; tc++)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
#define SZ(x)                   (int)x.size()
#define ff                      first
#define ss                      second
#define FF                      fflush(stdout);
#define infi                    0x3f3f3f3f
#define infl                    0x3f3f3f3f3f3f3f3f
#define ms(AR,x)                memset(AR,x,sizeof AR);
#define case                    printf("Case %lld: ",tc);
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;


/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution {
public:
    string a,b;
    int n,m;

    int dp[2002][2002];
    int last;
    int solve(int i,int j){

        if(i==n && j==m)    return 1;

        if(i==n){
            if(j>last) return 1;
            return 0;
        }

        if(i==n || j==m)    return 0;

        int &ans = dp[i][j];
        if(ans!=-1) return ans;
        ans = 0;

        if(b[j]>='a' && b[j]<='z'){
            if(a[i]!=b[j])  return ans = 0;
            return ans = solve(i+1,j+1);
        }
        if(b[j]=='?')   return ans = solve(i+1,j+1);
        else{
            for(int k = i; k<=n && ans==0; k++){
                ans|=solve(k,j+1);
            }
        }
        return ans;
    }

    bool isMatch(string s, string p) {
        a = s;
        b = p;
        n = s.size();
        m = p.size();
        if(n==0){
            for(int i = 0; i<m; i++){
                if(p[i]!='*')  return 0;
            }
            return 1;
        }
        last = 0;
        for(int i = 0; i<m; i++){
            if(p[i]=='*')   continue;
            last = i;
        }
        memset(dp,-1,sizeof dp);
        return solve(0,0);
    }
};
// @lc code=end






main(){
//read;


    string a,b;
    cin >> a >> b;

    Solution X;
    int x = X.isMatch(a,b);

    cout << x << endl;






    return 0;
}

