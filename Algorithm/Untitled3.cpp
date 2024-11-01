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


#define mx 200007

const ll MOD = 1e9 + 7;


ll prefB[mx], pwrB[mx];


int main(){
//read;

    pwrB[0] = 1;
    ll base = 487;
    for(ll i = 1; i<mx; i++){
        pwrB[i] = base * pwrB[i-1];
        pwrB[i]%=MOD;
    }

    for(ll i = 0; i<mx; i++){
        prefB[i] = (1ll * pwrB[i] * '1' )%MOD;
        if(i) {
            prefB[i] += prefB[i-1];
        }
        prefB[i] %= MOD;
    }


    TT{
        int n,m;
        sii(n,m);
        string s;
        cin >> s;
        s = " " + s;

        vector<ll> prefTxt (n + 5, 0), suffTxt (n + 5, 0);
        vector<int> count1 (n + 5, 0);

        for(ll i = 1; i<=n; i++){
            if(s[i] == '1')   count1[i] = 1;
            count1[i] += count1[i-1];
        }

        for(ll i = 1; i<=n; i++){
            if(s[i] == '1'){
                prefTxt[i] = (1ll * pwrB[i-1] * '1') % MOD;
            }
            suffTxt[i] = prefTxt[i];
            prefTxt[i] += prefTxt[i-1];
            prefTxt[i] %= MOD;
        }

        for(ll i = n; i>=0 ; i--) {
            suffTxt[i] += suffTxt[i+1];
        }

        set<ll> st;

        for(ll itr = 0; itr < m; itr++) {
            int l,r;
            sii(l,r);
            int one = count1[r] - count1[l-1];

            if(one == 0){
                st.insert(prefTxt[n]);
                continue;
            }


            ll lenHash = prefB[one - 1]%MOD;
            ll placedHash = (lenHash * pwrB[n-r])%MOD;
            ll totHash = (prefTxt[l-1] + suffTxt[r+1] + placedHash)%MOD;
            st.insert(totHash);
        }

        printf("%d\n", SZ(st));

    }



    return 0;
}


