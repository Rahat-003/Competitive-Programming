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


vector<ll> ar = {0,1,1,1,3,8,21,43,69,102,145};



main(){
//read;


while(SZ(ar)!=30000)    ar.pb(0);


int n,tc = 0;

while(1){
    si(n);
    if(n==0)    break;
    cout<<"Case #"<<++tc<<": ";
    if(ar[n]){
        cout<<ar[n]<<endl;
        continue;
    }
    deque<int> xx,yy,dq;
    for(int i = 0; i<n; i++)    dq.pb(i);
    xx.pb(0);
    dq.pop_front();
    int fl = 1;
    while(SZ(dq)){
        if(fl){
            xx.push_front(le(dq));
            dq.pop_back();
            if(SZ(dq)){
                xx.pb(le(dq));
                dq.pop_back();
            }
        }
        else{
            xx.push_front(fe(dq));
            dq.pop_front();
            if(SZ(dq)){
                xx.pb(fe(dq));
                dq.pop_front();
            }
        }
        fl^=1;
    }

    dq.clear();
    for(int i = n-1; i>=0; i--){
        if(i%2==0)  yy.pb(i);
        else yy.push_front(i);
    }

    ll p = 0,q = 0;
    for(int i = 0; i<n; i++){
        ll a = xx[i],b = xx[(i+1)%n];
        ll c = yy[i],d = yy[(i+1)%n];
        p+=a*b;
        q+=c*d;
    }
    ar[n] = q-p+1;
    cout<<ar[n]<<endl;

}




return 0;
}



