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
#define FOR(i,n)                for(int i = 1; i<=n; i++)
#define REP(i,n)                for(int i = 0; i<n;  i++)
#define TT                      long long TC;  scanf("%lld",&TC);  while(TC--)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;
#define mx 1005

vector<int> v[mx];
bool vis[mx];

struct tree_dia_centre{
    vector<int> L,par;

    void dfs(int u,int a){
        vis[u] = 1;
        L[u] = L[a] + 1;
        par[u] = a;
        for(int i:v[u]){
            if(i==a)    continue;
            dfs(i,u);
        }
    }

    tree_dia_centre(int root){
        L = vector<int> (mx,0);
        par = L;
        dfs(root,0);
        int x = 0,id;
        for(int i = 1; i<mx; i++){
            x = max(x,L[i]);
            if(x==L[i]) id = i;
        }
        L = vector<int> (mx,0);

        dfs(id,0);
    }
    pii dia_centre(){
        vector<int> xx;
        int s = 0,w = 0;
        for(int i = 1; i<mx; i++){
            w = max(w,L[i]);
            if(w==L[i]) s = i;
        }
        while(s!=0){
            xx.pb(s);
            s = par[s];
        }
        return pii(w - 1,xx[w/2]);
    }
};



main(){
//read;
int n,m;
cin>>n;

for(int i = 1; i<n; i++){
    int a,b;
    cin>>a>>b;
    v[a].pb(b);
    v[b].pb(a);
}



memset(vis,0,sizeof vis);

tree_dia_centre X(1);

pii dia = X.dia_centre();

cout<<dia.first<<endl;
cout<<"centre "<<dia.second<<endl;

return 0;
}
