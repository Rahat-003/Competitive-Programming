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

struct node{
    int max_val,min_val;
    node(){};
    node(int a,int b){ max_val = a, min_val = b; }
};

namespace sparse_table{
//  indexing starts from 1 |
    int N,sz;
    struct sample{
        vector<vector<node>> table;
        sample(auto &ar){
            N = (int)ar.size();
            sz = log2(N)+3;
            table = vector<vector<node>>(N+3);
            for(int i = 0; i<=N; i++)   table[i] = vector<node>(sz);
            for(ll i = 1; i<=N; i++)    table[i][0] = node(ar[i],ar[i]);
            for(ll i = 1,k = 1; i<log2(N); i++,k*=2){
                for(ll j = 1; j<=N; j++){
                    if(j-k<=0)  continue;
                    table[j][i].max_val = max(table[j][i-1].max_val,table[j-k][i-1].max_val);
                    table[j][i].min_val = min(table[j][i-1].min_val,table[j-k][i-1].min_val);
                }
            }
        }
        node query(int l,int r){
            ll len = log2(r-l+1),k = 1ll<<len;
            node x = table[r][len],y = table[l+k-1][len];
            return node(max(x.max_val,y.max_val),min(x.min_val,y.min_val));
        }
};
}

main(){
//read;
int N;
cin>>N;

vector<int> ar(N+3);

for(int i = 1; i<=N; i++)
    cin>>ar[i];

sparse_table::sample S(ar);

while(1){
    int l,r;
    cin>>l>>r;
    node x = S.query(l,r);
    cout<<x.max_val<<" "<<x.min_val<<endl;
}


return 0;
}
