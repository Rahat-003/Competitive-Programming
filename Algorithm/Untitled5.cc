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



struct Hash{
    ll b1 = 509,b2 = 919,sz;
    string s;
    vector<ll> pow1,pow2,h1,h2,Rh1,Rh2;
    ll mod1 = 998244353ll,mod2 = 100030001ll;
    Hash(string p){
        pow1.clear(); pow2.clear(); h1.clear(); h2.clear(); s = p; sz = s.size();
        pow1.pb(1); pow2.pb(1);
        for(ll i = 1 ; i < sz+2 ; i++){
            pow1.pb((1ll*pow1[i-1]*b1)%mod1);
            pow2.pb((1ll*pow2[i-1]*b2)%mod2);
        }
        h1.pb(s[0]); h2.pb(s[0]);
        Rh1 = vector<ll>(sz+2,0);
        Rh1[sz-1] = s[sz-1];    Rh2 = Rh1;
        for(ll i = 1,j = sz-2; i<sz ; i++,j--){
            h1.pb((1ll*h1.back()*b1 + s[i])%mod1);
            h2.pb((1ll*h2.back()*b2 + s[i])%mod2);
            Rh1[j] = (1ll*Rh1[j+1]*b1 + s[j])%mod1;
            Rh2[j] = (1ll*Rh2[j+1]*b2 + s[j])%mod2;
        }
    }
    pll query(ll i, ll j){
        pll res = make_pair(h1[j],h2[j]) ;
        if(i>0)
        res = make_pair((res.first-1ll*h1[i-1]*pow1[j-i+1])%mod1,(res.second-1ll*h2[i-1]*pow2[j-i+1])%mod2 ) ;
        res = make_pair((res.first%mod1+mod1)%mod1,(res.second%mod2+mod2)%mod2);
        return res;
    }

    // Reverse Query
    pll Rquery(ll i,ll j){
        pll res = make_pair(Rh1[i],Rh2[i]) ;
        if(j==sz-1) return res;
        res = {(Rh1[i] - 1ll*Rh1[j+1]*pow1[j-i+1])%mod1,(Rh2[i] - 1ll*Rh2[j+1]*pow2[j-i+1])%mod2};
        res = {(res.first%mod1+mod1)%mod1,(res.second%mod2+mod2)%mod2};
        return res;
    }

    bool isPalindrome(ll i,ll j){
        if(i>j) return false;
        return query(i,j)==Rquery(i,j);
    }
};




main(){
//read;









    return 0;
}




