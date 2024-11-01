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
#define case                    printf("Case %lld:\n",tc);
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;

ll Mul(ll a,ll b,ll Mod){
    ll Ans=0;
    while(b){
        if(b&1) {Ans+=a; if(Ans>=Mod) Ans-=Mod;}
        a+=a; if(a>=Mod) a-=Mod;
        b>>=1;
    }
    return Ans;
}

ll bigMod(ll n,ll r,ll Mod){
    if(r==0) return 1LL;
    ll ret=bigMod(n,r/2,Mod);
    ret=Mul(ret,ret,Mod);
    if(r%2==1) ret=Mul(ret,n,Mod);
    return ret;
}

//Miller-Rabin
bool witness(ll wit,ll n){
  if(wit>=n) return false;

  int s=0; ll t=n-1;
  while(t%2==0) s++,t/=2;

  wit=bigMod(wit,t,n);
  if(wit==1 || wit==n-1) return false;

  for(int i=1;i<s;i++){
    wit=Mul(wit,wit,n);
    if(wit==1) return true;
    if(wit==n - 1) return false;
  }
  return true;
}

//Is n prime?
bool miller(ll n){
  if(n==2) return true;
  if(n%2==0 || n<2) return false;
  if(witness(2,n) || witness(7,n) || witness(61,n)) return false;
  return true;
}

// Pollard's Rho
// a must not equal 0 or -2.
// returns a divisor, a proper one when succeeded, equal to n if failed
// in case of failure, change a
ll rho(ll n,ll a) {
  auto f=[&](ll x) {return (Mul(x,x,n)+a)%n; };
  ll x=2,y=2;
  for(int i=1;;i++){
    x=f(x); y=f(f(y));
    ll d=__gcd(n,abs(x-y));
    if(d!=1) return d;
  }
  return n;
}

ll get_factor(ll n){
  if(n%2==0) return 2;
  if(n%3==0) return 3;
  if(n%5==0) return 5;
  while(true){
    ll a=2+rand()%100;
    ll d=rho(n,a);
    if(d!=n) return d;
  }
  return n;
}

void factorize(ll n,vector<ll> &x) {
  if(n==1) return;
  else if(miller(n)) x.push_back(n);
  else{
    ll d=get_factor(n);
    factorize(d,x);
    factorize(n/d,x);
  }
}

vector<ll>factorize(ll n) {vector<ll>x; factorize(n, x); return x;}

vector<pll>Factors;
vector<ll>Divisors;

void findDiv(int pos,ll val){
    if(pos<0) {Divisors.push_back(val); return;}
    ll Now=1;
    for(int i=0;i<=Factors[pos].second;i++){
        findDiv(pos-1,val*Now);
        Now=Now*Factors[pos].first;
    }
}

void findAllDiv(ll n){
    vector<ll>now=factorize(n);
    sort(now.begin(),now.end());

    Factors.clear();
    Divisors.clear();
    int Count=1;
    for(int i=1;i<now.size();i++){
        if(now[i]==now[i-1]) Count++;
        else {Factors.push_back({now[i-1],Count}); Count=1;}
    }
    Factors.push_back({now.back(),Count});
    findDiv(Factors.size()-1,1);
}

main(){

ll n;
cin>>n;
findAllDiv(n);

cout<<Divisors.size()<<endl;
sort(all(Divisors));

for(auto i:Divisors)
    cout<<i<<" ";


return 0;
}



