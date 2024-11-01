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
#define ms(AR,x)                memset(AR,x,sizeof AR);
#define case                    printf("Case %lld: ",tc);
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;

#define mx 21

const ll MX = 1e9;


//vector<ll> v;
//map<ll,ll> mp;
//
//void fn(ll n = 0){
//    if(n>MX)    return;
//    if(n){
//        v.pb(n);
//        mp[n] = 1;
//    }
//    fn(n*10+4);
//    fn(n*10+7);
//}


main(){
//read;

ll fct[30];
fct[0] = 1;

for(ll i = 1; i<=20; i++){
    fct[i] = fct[i-1]*i;
}
cout<<fct[20]<<endl;
/// 1 <= n,p <= 1e18

ll n,p;

sll(n,p);

if(n<mx && p>fct[n]){
    cout<<-1;
    return 0;
}


//sort(all(v));

vector<pll> xx;

set<ll> st;

ll pos,first;

for(ll i = n,j = 1; ; i--,j++){
    if(fct[j]>=p){
        pos = i;
        first = i-1;
        for(ll k = i; k<=n; k++)    st.insert(k);
        break;
    }
}



while(pos<=n){
    ll sz = SZ(st);
    ll cnt = 0,cur = fe(st),q = 0;
    for(ll i:st){
        cnt++;
        ll l = (cnt-1)*fct[sz-1] + 1,r = cnt*fct[sz-1];
        if(l<=p && p<=r){
            cur = i;
            q = cnt;
            break;
        }
    }
    st.erase(cur);
    xx.pb(pll(pos,cur));
    ll cost = (q-1)*fct[sz-1];
    p-=cost;
    pos++;
}

cout<<endl;
if(first>0){
    cout<<"First "<<first<<" numbers are in their own positions"<<endl<<endl;
    if(SZ(xx)){
        cout<<"Rest numbers are"<<endl;
    }
}


for(auto i:xx){
    cout<<i.ff<<"th position e "<<i.ss<<endl;
}


return 0;
}



