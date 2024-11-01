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
//#define ff first
//#define ss second
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

#define mx 200002

ll  dp[mx];
ll P = 998244353ll;
//
ll n;

ll fn(ll pos){
    if(pos==1)  return 1;
    ll &ans = dp[pos];
    if(ans!=-1)  return ans;
    ans = 0;
    for(ll i = 1; i<pos; i++){
        ans+=fn(i);
        ans%=P;
        ans+=fn(pos/(i+1))%P;
        ans%=P;
    }
    return ans%P;
}


ll fn(ll pos,ll i){
    ll l = pos/(i+1);
//    if(pos%(i+1))
        l++;
    ll r = pos/i;
    return r - l + 1;
}

    vector<pll> V;

void check(ll n){
    ll p = 1e9 + 7;
//sll(n,p);
    V.clear();
    dp[1] = 2;
    ll tot = 0;

    //cout<<fn(n,463)<<endl;


    for(ll i = n; i<=n; i++){
        tot = (tot + dp[i-1])%p;
        ll ans = tot;
        ll cnt = 0,last = -1;
        for(ll j = 2; j<=i ; j++){
            ll cur = i/j;
            ll freq = fn(i,cur);
            if(fn(i,j)>0){
                ll y = dp[cur]*freq%p;
                ans = (ans+y)%p;
                cnt++;
                last = j;
                V.pb(pii(cur,freq));
            }
            else{
    //            cout<<"Hola "<<i<<" "<<freq<<endl;
    //            cout<<"HI "<<i<<" j "<<j<<" k "<<cur<<endl;
                for(ll k = cur; k>=1; k--){
                    freq = fn(i,k);
                    ll y = dp[k]*freq%p;
                    ans = (ans+y)%p;
                    cnt++;
                    V.pb(pii(k,freq));
                }
                break;
            }
        }
    //    cout<<"HI "<<i<<" "<<cnt<<" "<<last<<endl;
        dp[i] = ans;
    }

    sort(all(V));

}


int main(){
//read;

//cin>>n;

memset(dp,-1,sizeof dp);

fn(1999);

for(ll i = 2; i<=50; i++){
//    cout<<i<<" "<<dp[i]<<endl;
    ;
}

ll tot = 1;
//
//for(ll i = 2; i<=100; i++){
//    n = i;
//    ll ans = fn(n);
//    cout<<"HI "<<n<<" "<<ans<<" "<<ans - tot<<endl;
//    tot+=dp[i];
//}

//
//cout<<fn(n);

vector<int> ar(500000,0);

n = 2e5;

cin>>n;

vector<ll> v;
for(ll i = 2; i<=n; i++)
    v.pb(n/i);

sort(all(v));

for(ll i:v){
//    cout<<i<<" ";
    ar[i]++;
}
ll cnt = 0;

vector<ll> xx;

check(n);

int id = 0;

for(int i = 1,j = n; i<SZ(ar); i++,j--){
    if(ar[i]==0){
//        cout<<"HI "<<i<<" ("<<ar[i]<<" , "<<fn(n,i)<<") ";
//        cout<<endl;
        continue;
    }
//    cout<<""<<i<<" "<<ar[i]<<endl;
    cnt++;

    if(V[id].first!=i || V[id].second!=ar[i]){
        cout<<"-1";
        return 0;
    }
    id++;
//    ll q = n/j;
//    cout<<endl;
    xx.pb(i);
//    if(q==ar[i])    cout<<q<<" ";
//    else cout<<" -1 ";
//    cout<<endl;
}

//cout<<endl;
reverse(all(xx));

//for(int i = 0,j = 2; i<SZ(xx); i++,j++)
//    cout<<xx[i]<<" "<<n/j<<" GS "<<j<<endl;;

//cout<<cnt<<endl;

return 0;
}
