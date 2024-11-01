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


#define mx 200004

deque<int> dq[mx];

pii id[mx];

int cur_top[mx];

deque<pii> cur;

main(){
//read;

int n,m;

sii(n,m);

for(int i = 1; i<=m; i++){
    int x;
    si(x);

    for(int j = 1; j<=x; j++){
        int p;
        si(p);
        if(id[p].ff==0) id[p].ff = i;
        else id[p].ss = i;
        dq[i].pb(p);
    }
    cur_top[i] = fe(dq[i]);
}


for(int i = 1; i<=n; i++){
    int a = id[i].ff,b = id[i].ss;
    if(fe(dq[a])==fe(dq[b]))    cur.pb(pii(a,b));
}


while(SZ(cur)){
    pii u = fe(cur);
    cur.pop_front();
    int a = u.ff,b = u.ss;
    if(a>0 && b>0 && SZ(dq[a]) && SZ(dq[b]) && fe(dq[a])==fe(dq[b])){
        dq[a].pop_front();
        dq[b].pop_front();
    }
    else continue;
//    cout<<"HI "<<a<<" "<<b<<endl;

    int x = -1,y = -1;

    if(SZ(dq[a]))   x = fe(dq[a]), cur_top[a] = x;
    else cur_top[a] = -1;

    if(SZ(dq[b]))   y = fe(dq[b]), cur_top[b] = y;
    else cur_top[b] = -2;

    if(x!=-1){
        int p = id[x].ff,q = id[x].ss;
        if(p==a)    swap(p,q);
        if(cur_top[p]==x)   cur.pb(pii(a,p));
    }

    if(y!=-1){
        int p = id[y].ff,q = id[y].ss;
        if(p==b)    swap(p,q);
        if(cur_top[p]==y)   cur.pb(pii(b,p));
    }

}


for(int i = 1; i<=m; i++){
    if(SZ(dq[i])){
        cout<<"No";
        return 0;
    }
}

cout<<"Yes";


return 0;
}

