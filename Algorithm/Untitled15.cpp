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

#define mx 300005

int a[mx], d[mx];

set(int) st;

pii adj(int x){
    int id = st.ook(x);
    int nxt = fbo(st,id);
    if(nxt==x)  nxt = fbo(st,id+1);
    return pii(fbo(st,id-1), nxt);
}



int main(){
//read;

    TT{
        st.clear();
        int n;
        si(n);

        a[0] = a[n+1] = 0;
        d[0] = d[n+1] = infi;

        for(int i = 1; i<=n; i++)   si(a[i]);
        for(int i = 1; i<=n; i++)   si(d[i]);

        vector<int> tmp;

        for(int i = 1; i<=n; i++){
            tmp.pb(i);
            st.insert(i);
        }
        st.insert(0);
        st.insert(n+1);

        vector<int> ans;

        while(SZ(tmp)){
            vector<int> tmp2;

            for(int i:tmp){
                pii cur = adj(i);
                int x = cur.ff, y = cur.ss;
                if(d[i]<a[x] + a[y]){
                    tmp2.pb(i);
                }
            }

            tmp.clear();
            ans.pb(SZ(tmp2));
            for(int i:tmp2) st.erase(i);

            for(int i:tmp2){
                pii cur = adj(i);
                int x = cur.ff, y = cur.ss;
                if(x>0)     tmp.pb(x);
                if(y<=n)    tmp.pb(y);
            }

            sort(all(tmp));
            un(tmp);

        }

        while(SZ(ans)<n)    ans.pb(0);


        for(int i:ans)  printf("%d ",i);

        puts("");

    }




    return 0;
}

