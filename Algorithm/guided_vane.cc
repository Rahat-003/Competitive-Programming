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


#define pi acos(-1)
#define mx 3000



main(){
read;

freopen(

        "ws12_40deg_guided_vane.txt"

,"w",stdout);

    double pm,n;

    cin >> n >> pm;

    double F = pm/(5e-3 * pi * n);

    int ar[mx+32];
    double br[mx+33],cr[mx+33];

    double tot = 0;
    for(int i = 0; i<mx; i++){
        cin >> ar[i] >> br[i] >> cr[i];
        tot+=br[i];
    }

    tot/=3001.0;

    double diff = F-tot;

    double q = 0;

    for(int i = 0; i<mx; i++){
        br[i]+=diff;
        if(i==0)    br[i]+=diff;
        q+=br[i];
    }

//    printf("%.10f %.10f\n",F,q/3001.0);
    cout << "wind speed = \n";
    cout << "n = " << n << endl;
    cout << "Force = ";
    printf("%.12f\n",F);

    cout << endl << endl << endl;

    puts("0 0.0000000 0.0000000");
    for(int i = 0; i<mx; i++){
        printf("%d %.10f %.10f\n",i+1,br[i],cr[i]   );
    }


    return 0;
}


