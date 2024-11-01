/**

    https://atcoder.jp/contests/arc089/tasks/arc089_b

    Prefix sum 2d
    Subrectangle update
    Sum Query in any subrectangle (After all updates are done)
*/

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
#define SZ(x)                   (ll)x.size()
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
typedef                         pair<ll,ll> pii;

#define mx 2005

ll ar[mx][mx];


void update(ll a,ll b,ll c,ll d,ll x){
    /***
        2d array must be 1-indexed
        else a++,b++,c++,d++;

        For 2d Co-ordinate system
        (a,b) = Bottom Left Point
        (c,d) = Top Right Point
        Add each cell of the rectangle (a,b),(c,d) by value x

        After all updates are made, Do iteration for prefix sum calculation of 2d grid
    */
    ar[a][b]+=x;
    ar[c+1][b]-=x;
    ar[a][d+1]-=x;
    ar[c+1][d+1]+=x;
}

ll query(ll a,ll b,ll c,ll d){
    ll x = ar[c][d]+ar[a-1][b-1]-ar[a-1][d]-ar[c][b-1];
    return x;
}


main(){
//read;


    TT{
        ll a,b,c,d,x;
        cin >> a >> b >> c >> d >> x;
        update(a,b,c,d,x);
//        ar[a][b]+=x;
//        ar[c+1][b]-=x;
//        ar[a][d+1]-=x;
//        ar[c+1][d+1]+=x;

    }

    /// Iteration for prefix sum calculation
    for(ll it = 0; it<2; it++){
        for(ll i = 1; i<mx; i++){
            for(ll j = 1; j<mx; j++){
                ar[i][j]+=ar[i][j-1];
            }
        }
        for(ll i = 1; i<mx; i++){
            for(ll  j = 1; j<mx; j++){
                ar[i][j]+=ar[i-1][j];
            }
        }
    }
    /// Iteration end;

    ll q;
    cin >> q;

    while(q--){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        ll w = query(a,b,c,d);
//        ll w = ar[c][d]+ar[a-1][b-1]-ar[a-1][d]-ar[c][b-1];
        cout << w << endl;
    }





    return 0;
}



