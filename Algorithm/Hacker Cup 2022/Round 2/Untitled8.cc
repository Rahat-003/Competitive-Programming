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
#define infi                    0x3f3f3f3f
#define infl                    0x3f3f3f3f3f3f3f3f
#define ms(AR,x)                memset(AR,x,sizeof AR);
#define case                    printf("Case #%lld: ",tc);
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;

set(int) st[4];

int fn(int fl,int z){
    int id = st[fl].ook(z+1);
    return id;
}


main(){
read;
write;
    TT{
        int n,m;
        si(n);
        si(m);

        for(int i:{1,2,3}){
            st[i].clear();
        }

        int ar[n+2];
        for(int i = 1; i<=n; i++){
            si(ar[i]);
            st[ar[i]].insert(i);
        }


        ll ans = 0;

        while(m--){
            int x,y,z;
            siii(x,y,z);
            st[ar[x]].erase(x);
            st[y].insert(x);
            ar[x] = y;

            int tot = SZ(st[1]) + 2*SZ(st[2]) + 3*SZ(st[3]);

//            cout << "QQ " << tot << endl;
//            return 0;

            if(tot&1){
                ans+=-1;
                continue;
            }

            int a1 = fn(1,z), a2 = SZ(st[1]) - a1;
            int b1 = fn(2,z), b2 = SZ(st[2]) - b1;
            int c1 = fn(3,z), c2 = SZ(st[3]) - c1;

            int xx = a1 + b1*2 + c1*3, yy = tot - xx;

//            cout <<"JA " << tot << " " << xx << " " << yy << endl;

            if(xx==yy)  continue;

            if(abs(xx-yy)%2){
                ans+=-1;
                continue;
            }
//            puts("-1");

            if(xx<yy){
                swap(a1,a2);
                swap(b1,b2);
                swap(c1,c2);
                swap(xx,yy);
            }
//            cout << "xx "<<xx << " " << yy << endl;

            int cur = 0;
            int diff = xx - yy;
            int p = min( {diff/4,c1,a2});
            p = max(p,0);

            diff-=p*4;
            cur+=p;
            c1-=p;
            a2-=p;

            c2+=p;
            a1+=p;

            p = min({ diff/2,b1,a2 });
            p = max(p,0);

            diff-=p*2;
            cur+=p;
            b1-=p;
            a2-=p;

            b2+=p;
            a1+=p;


            p = min({ diff/2,c1,b2 });
            p = max(p,0);
            diff-=p*2;
            cur+=p;
            c1-=p;
            b2-=p;

            c2+=p;
            b1+=p;
//            cout << "HI " << diff << " cur " << cur << endl;
            if(diff==0) ans+=cur;
            else ans-=1;


        }
        case;
        printf("%lld\n",ans);
//        cout << ans << endl;
    }







    return 0;
}


