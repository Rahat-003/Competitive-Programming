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


#define mx 200005

vector<int> par,vis;

vector<pii> v[mx];

int tail;

vector<int> xx;

bool dfs(int u,int a,int lmt){
    vis[u] = 1;
    par[u] = a;
    for(auto qq:v[u]){
        int i = qq.ss;
        if(i==a)    continue;
        if(qq.ff<lmt)   break;

        if(!vis[i]) return dfs(i,u,lmt);
        else{
            int tail = u;

            if(SZ(xx)==0){
                while(tail){
                    xx.pb(tail);
                    tail = par[tail];
                }
            }
            return 1;
        }
    }
    return false;
}


int n;

void clr(){
    par = vector<int> (n+2,0);
    vis = par;
    tail = 0;
}


int main(){
//read;


    TT{

        int m;
        sii(n,m);

        map<pii,int> mp;

        while(m--){
            int a,b;
            sii(a,b);
            int c;
            si(c);
//            cin >> c;

//            if(a>b) swap(a,b);

//            mp[pii(a,b)] = c;
//            mp[pii(b,a)] = c;

            v[a].pb(pii(c,b));
            v[b].pb(pii(c,a));
        }

        for(int i = 1; i<=n; i++){
            sort(all(v[i]));
            reverse(all(v[i]));
        }

        int l = 1,r = 1e6,ans = 1e6;

        vector<int> cycle;

        for(int i = 1; i<=10; i++){
            clr();
            cout << dfs(1,0,i) << " ";
        }

        cout << endl;

//        while(l<=r){
//            m = l+r>>1;
//
//            xx.clear();
//
//
//            bool flag = 0;
//
//            for(int i = 1; i<=n; i++){
//                if(vis[i])  continue;
//                flag = dfs(i,0,m);
//                if(flag){
//                    cycle = xx;
//                    break;
//                }
//            }
//
//            if(flag)    r = m - 1, ans = m;
//            else l = m + 1;
//        }

//        ans = mp[pii(le(cycle),fe(cycle))];
//
//        for(int i = 1; i<SZ(cycle); i++){
//            int x = cycle[i-1], y = cycle[i];
//            ans = min(ans,mp[pii(x,y)]);
//        }

        printf("%d %d\n", ans,SZ(cycle));
        for(int i:cycle){
            printf("%d ",i);
        }
        puts("");
    }




    return 0;
}

