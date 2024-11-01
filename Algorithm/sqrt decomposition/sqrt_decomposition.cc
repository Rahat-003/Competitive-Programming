/************
    Square Root Decomposition
    Given n integers and queries. No update
    for each query [l,r], find (a,b), where
    a = maximum frequency of all numbers from l to r
    b = total no. of integers which have frequency of a;

    https://youtu.be/eBGa5w1nsEw?t=8633
*
*
*
*************/

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
#define TT                      long long TC;  scanf("%lld",&TC);  while(TC--)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
#define assign(v,n,x)           v.clear(); for(int I = 0; I<n; I++)    v.pb(x);
#define SZ(x)                   (int)x.size()
#define ff                      first
#define ss                      second
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;


#define mx 500002

int ar[mx],n;
pii ans[mx];
vector<pair<pii,int>> qq;
int ara[mx],tmp[mx];

deque<pii> v[mx];

int block(int x){
    --x;
    int len = sqrt(n),p = x/len;
    return p+1;
}

main(){
//read;

si(n);

for(int i = 1; i<=n; i++)
    si(ar[i]);

int q;
si(q);

for(int i = 1; i<=q; i++){
    int l,r;
    sii(l,r);
    if(block(l)==block(r)){
        qq.pb({pii(l,r),i});
        continue;
    }
    v[r].pb(pii(l,i));
}

for(int i = 0; i<mx; i++)
    sort(all(v[i]));

//sort(all(qq));

int len = sqrt(n);
/*
20
4 5 14 12 7 6 4 3 8 9 6 6 5 3 9 9 5 12 12 10
1
14 18
ans = 2 1
*/
for(int i = 1; i<=n; i+=len){
    memset(ara,0,sizeof ara);
    int mx_cnt = 0,ache = 0;
    for(int k = i; k<=n; k++){
        int x = ar[k];
        ara[x]++;
        if(ara[x]==mx_cnt)   ache++;
        else if(ara[x]>mx_cnt)  mx_cnt = ara[x],ache = 1;
        while( SZ(v[k]) && v[k][0].first<=i ){
            int a = mx_cnt,b = ache;
            vector<int> waste;
            for(int j = i-1; j>=v[k][0].first; j--){
                int y = ar[j];
                tmp[y]++;
                if(ara[y]+tmp[y]==a)   b++;
                else if(ara[y]+tmp[y]>a)    a = ara[y]+tmp[y],b = 1;
                waste.pb(y);
            }
            ans[v[k][0].ss] = pii(a,b);
            v[k].pop_front();
            for(int j:waste)    tmp[j]--;
        }
    }
}

memset(ara,0,sizeof ara);

for(auto i:qq){
    int mx_cnt = 0,ache = 0;
    vector<int> waste;
    for(int k = i.ff.ff; k<=i.ff.ss; k++){
        int x = ar[k];
        ara[x]++;
        if(ara[x]==mx_cnt)   ache++;
        else if(ara[x]>mx_cnt)  mx_cnt = ara[x],ache = 1;
        waste.pb(x);
    }
    for(int j:waste)    ara[j]--;
    ans[i.ss] = pii(mx_cnt,ache);
}

for(int i = 1; i<=q; i++)
    printf("%d %d\n",ans[i].ff,ans[i].ss);

return 0;
}
