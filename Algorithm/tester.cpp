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
#define write                   freopen("input.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;





main(){

write;


int n,k;
cin>>n>>k;

cout<<n<<" "<<k<<endl;

vector<int> v;

int cnt = 0;

for(int i = 0; i<n; i++){
    int x = rand()%6;
    if(x==4 && cnt<10)    v.pb(n),cnt++;
    else v.pb( (1+x)*3);
}


for(int i:v)
    cout<<i<<" ";
cout<<endl;



return 0;
}



