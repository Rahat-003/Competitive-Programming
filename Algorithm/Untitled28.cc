#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define lb lower_bound
#define ub upper_bound
#define fe(x) (*(x.begin()))
#define le(x) (*(x.rbegin()))
#define pb push_back
#define fbo(x,id) (*(x.find_by_order(id)))
#define ook(y) order_of_key(y)
#define all(x) (x).begin(),(x).end()
#define si(a)  scan(a)
#define sii(a,b) si(a),si(b)
#define siii(a,b,c) sii(a,b),si(c)
#define pr printf
#define rep(i,a,b) for(ll i = a; i<=b;  i++)
#define un(x) x.erase(unique(all(x)), x.end())
#define TT long long TC;  scanf("%lld",&TC);  for(ll tc = 1; tc<=TC; tc++)
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define set(x) tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
#define assign(v,n,x) v.clear(); for(int I = 0; I<n; I++)    v.pb(x);
#define SZ(x) (int)x.size()
#define FF fflush(stdout)
#define ff first
#define ss second
#define FF fflush(stdout);
#define ms(AR,x) memset(AR,x,sizeof AR);
#define case printf("Case %lld: ",tc);
#define ANS(fl) puts(fl? "YES" : "NO");
#define Ans(fl) puts(fl? "Yes" : "No");
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
template<class T> inline void scan(T &x) {
    register char c = getchar();x = 0;
    int neg = 0;
    for(; ((c<48 or c>57) && c != '-'); c = getchar());
    if(c=='-'){neg = 1;c = getchar();}
    for(; c>47 && c<58 ; c = getchar()){x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x = -x;
}
inline long long bigmod(long long p,long long e,long long M){
    long long ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return ret;
}



int main(){
//read;

TT{
    int n;
    si(n);
    string s;
    cin>>s;

    string a,b;

    bool fl = 0;
    int l1,r1,l2,r2;
    for(int i = n/2; i<n; i++){
        if(s[i]=='0'){
            l1 = 0,r1 = i;
            l2 = 0,r2 = i-1;
            fl = 1;
            break;
        }
    }

    if(fl==0){
        for(int i = 0; i<n/2; i++){
            if(s[i]=='0'){
                l1 = i,r1 = n-1;
                l2 = i+1,r2 = n-1;
                fl = 1;
                break;
            }
        }
        if(fl==0){
            l1 = 0,r1 = n-2;
            l2 = 1,r2 = n-1;
        }
    }
    l1++,r1++,l2++,r2++;
    cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;

}






return 0;
}

