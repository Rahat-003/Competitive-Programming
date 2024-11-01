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


string ar[10];

int n,k;

bool check(int x,int y){
    if(x<0 || x==n || y<0 || y==n)  return false;
    return ar[x][y]=='.';
}

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int ans,vis[10][10],L[10][10];
pii par[10][10];

void bfs(int sx,int sy){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            L[i][j] = 1000;
    }
    par[sx][sy] = {-1,-1};
    L[sx][sy] = 1;
    queue<pii> q;
    q.push(pii(sx,sy));
    while(SZ(q)){
        pii u = q.front();
        q.pop();
        int x = u.ff,y = u.ss;

        if(L[x][y]==k){
            while(par[x][y].ff!=-1){
                vis[x][y] = 1;
                pii cur = par[x][y];
                x = cur.ff;
                y = cur.ss;
            }
            ans++;
        }

        x = u.ff, y = u.ss;

        for(int i = 0; i<4; i++){
            int nx = x+dx[i],ny = y+dy[i];
            if(check(nx,ny)==0 || vis[nx][ny])  continue;
            int w = L[x][y] + 1;
            if(L[nx][ny]>w && w<=k){
                par[nx][ny] = pii(x,y);
                L[nx][ny] = w;
                q.push(pii(nx,ny));
            }
        }
    }
}

//map<ll,ll> dp[10][10];
//
//
//ll dfs(int x,int y,ll mask){
//    ll cnt = __builtin_popcountll(mask);
//    if(cnt==k)  return 1;
//    if(dp[x][y].find(mask)!=dp[x][y].end()) return dp[x][y][mask];
//    ll ans = 0;
//    for(int i = 0; i<4; i++){
//        int nx = x+dx[i],ny = y+dy[i];
//        if(check(nx,ny)==0) continue;
//        ll nmask = nx*n + ny;
//        ans+=dfs(nx,ny,mask|nmask);
//    }
//    dp[x][y][mask] = ans;
//}


main(){
//read;

sii(n,k);

for(int i = 0; i<n; i++)    cin >> ar[i];

ms(par,-1);

bfs(0,0);

//for(int i = 0; i<n; i++){
//    for(int j = 0; j<n; j++){
//        if(ar[i][j]=='#' || vis[i][j])   continue;
//        bfs(i,j);
//    }
//}

cout << ans;

return 0;
}

