#include                        <bits/stdc++.h>
#include                        <ext/pb_ds/assoc_container.hpp>
#define lb                      lower_bound
#define ub                      upper_bound
#define fe(x)                   (*(x.begin()))
#define le(x)                   (*(x.rbegin()))
#define pb                      push_back
#define load(node,n)            bool operator < (const node &n) const
#define fbo(x)                  find_by_order(x)
#define ook(x)                  order_of_key(x)
#define all(x)                  (x).begin(),(x).end()
#define FOR(i,n)                for(int i = 1; i<=n; i++)
#define REP(i,n)                for(int i = 0; i<n;  i++)
#define TT                      int TC;  scanf("%d",&TC);  while(TC--)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;

#define mx 300005

int table[mx][20],ar[mx],N;

void build(){
    int sz = log2(N);
    for(int i = 0; i<N; i++){
        table[i][0] = ar[i];
    }
    for(int i = 1,k = 1; i<=sz; i++,k*=2){
        for(int j = 0; j<N; j++){
            if(j-k<0)   continue;
            if(table[j-k][i-1]==0)  continue;
            table[j][i] = __gcd(table[j][i-1],table[j-k][i-1]);
        }
    }
}

int query(int l,int r){
    int x = log2(r-l+1);
    int a = table[ l-1 + (1<<x)][x];
    int b = table[r][x];
    return __gcd(a,b);
}

main(){
//read;

cin>>N;

REP(i,N)    cin>>ar[i];
build();

cout<<endl;

while(1){
    int a,b;
    cin>>a>>b;
    cout<<query(a,b)<<endl;

}

//REP(i,N){
//    cout<<ar[i]<<endl;
//    for(int j = 0; j<10; j++){
//        if(table[i][j]==0)  break;
//        cout<<table[i][j]<<" ";
//    }
//    cout<<endl<<endl;;
//}


return 0;
}
