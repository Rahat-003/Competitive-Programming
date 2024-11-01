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
#define case                    printf("Case #%lld: ",tc);
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;

ll ar[30][30];

ll L[30];

ll MX = 1e9;

vector<int> v[30];

void bfs(int u){
    for(ll i = 0; i<30; i++)    L[i] = MX;
    L[u] = 0;
    queue<int> q;
    q.push(u);
    while(SZ(q)){
        int u = q.front();
        q.pop();
        for(int i:v[u]){
            ll w = L[u] + 1;
            if(L[i]>w){
                L[i] = w;
                q.push(i);
            }
        }
    }
}


main(){
//read;
//write;


TT{
    for(int i = 0; i<30; i++)   v[i].clear();
    ms(ar,0);
    string s;
    cin>>s;
    int n = SZ(s);
    ll ans = MX;


    int k;
    si(k);
    for(int i = 0; i<k; i++){
        string p;
        cin>>p;
        int a = p[0] - 'A', b = p[1] - 'A';
        v[a].pb(b);
    }

    for(int i = 0; i<26; i++){
        bfs(i);
        for(int j = 0; j<26; j++){
            ar[i][j] = L[j];
        }
    }

    for(ll i = 0; i<26; i++){
        ll p = 0;
        for(ll j = 0; j<n; j++){
            int fl = s[j] - 'A';
            p+=ar[fl][i];
        }
        ans = min(ans,p);
    }
    case;
    if(ans==MX) ans = -1;
    cout << ans << endl;
}






return 0;
}

