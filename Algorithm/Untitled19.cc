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
#define assign(v,n,x)           v.clear(); for(int I = 0; I<n; I++)    v.pb(x);
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

#define mx 1005

const ll P = 1e9 + 7;

vector<ll> fct,inv;

ll bigmod(ll n,ll p,ll m){
    if(p==0)    return 1;
    if(p==1)    return n%m;
    ll x = bigmod(n,p/2,m)%m;
    if(p%2==0)  return (x*x)%m;
    return (((x*x)%m)*(n%m))%m;
}

void ini(){
    ll n = mx;
    fct = vector<ll> (n+5);
    inv = fct;
    fct[0] = 1;
    for(ll i = 1; i<=n; i++)
        fct[i] = (i*fct[i-1])%P;
    inv[n] = bigmod(fct[n],P-2,P);
    for(ll i = n-1; i>=0; i--){
        inv[i] = (inv[i+1]*(i+1))%P;
    }
}

ll ncr(ll n,ll r){
    if(n<r) return 0;
    ll a = fct[n],b = inv[r],c = inv[n-r];
    return (((a*b)%P)*c)%P;
}

ll npr(ll n,ll r){
    if(r<0 || n<r) return 0;
    return (ncr(n,r)*fct[r])%P;
}

ll d[mx];

main(){
//read;

ini();

d[0] = 1;
d[2] = 1;

for(ll i = 3; i<mx; i++){
    d[i] = (i-1)*((d[i-1]+d[i-2])%P);
    d[i]%=P;
}


TT{
    ll n,m,k;
    slll(n,m,k);

    ll ans = 0;

//    for(ll i = 0; i<=m-k; i++){
//        ll p = (ncr(m-k,i)*d[i])%P;
//        p = (p*ncr(n-m,m-k-i))%P;
//        p = (p*fct[m-k-i])%P;
//        p = (p*fct[n-m])%P;
//        p = (p*ncr(m,k))%P;
//        cout<<"HI "<<i<<" "<<p<<endl;
//        ans = (ans+p)%P;
//    }

    for(int i = max(0ll,2*m-k-n); i<=m-k; i++){
        ll p = 0;
        cout<<endl;
        for(int j = max(0ll,2*i-m+k); j<=i; j++){
            ll q = ncr(i,j)*d[j];
            q%=P;
            q*=npr(m-k-i,i-j);
            q%=P;
            q*=npr(n-m,m-k-i);
            q%=P;
            p+=q;
            p%=P;
            cout<<"QQ "<<i<<" "<<j<<" q "<<q<<" "<<p<<endl;
        }
        p*=ncr(m-k,i);
        p%=P;
        p*=fct[n-m];
        p%=P;
        ans+=p;
        ans%=P;
        cout<<"HI "<<i<<" "<<p<<endl;
    }
    cout<<"HOLA "<<ans<<" "<<ncr(m,k)<<endl;
    ans*=ncr(m,k);
    ans%=P;

    case;

    printf("%lld\n",ans);
}


//baki pos thake = m-k
//
//for i = 0 ... m-k
//    ll p = ncr(m-k,i)*d[i]*ncr(n-m,m-k-i)*(m-k-i)!*(n-m)!;
//    ans+=p;
//    ans*=ncr(m-k,i)*d[i]*(m-k-i)!




return 0;
}

