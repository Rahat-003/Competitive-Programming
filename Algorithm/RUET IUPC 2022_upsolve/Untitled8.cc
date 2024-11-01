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


vector<vector<int>> v;

map<int,int> mp;

void fn(){
    int len = SZ(v);
    if(len==1){
        for(int i = 0; i<len; i++){
            for(int j:v[i])
                mp[j]++;
        }
        return;
    }
//    mp.clear();
    vector<vector<int>> tmp;
    for(int i = 1; i<len; i++){
        vector<int> cur;
        for(int j:v[i-1]){
            cur.pb(j);
        }
        for(int j:v[i]){
            cur.pb(j);
        }
        tmp.pb(cur);
    }

//    cout<<SZ(v)<<" "<<SZ(tmp)<<endl;

    v = tmp;
    fn();
}




main(){
//read;

int n;
cin>>n;

for(int i = 1; i<=n; i++){
    vector<int> qq;
    qq.pb(i);
    v.pb(qq);
}

fn();

for(auto i:mp){
    cout<<i.ff<<" "<<i.ss<<endl;
}






    return 0;
}


