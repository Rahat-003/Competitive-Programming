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

//vector<ll> ar;

#define int ll

struct BIT{
    int SIZE;
    vector<int> TREE;
    BIT(int N){
        SIZE = N;
        TREE = vector<int>(SIZE+3,0);
    }

//    int sum(int i){
//        int x = 0;  for(; i; i-=i&-i)   x+=TREE[i];   return x;
//    }
    void done()
{
    for(int i = 1; i<SIZE; i++) TREE[i]+=TREE[i-1];
}
    void update(int i,int val){
        TREE[i]+=val;
//        for(; i<=SIZE; i+=i&-i)    TREE[i]+=val;
    }

    int query(int a,int b){
        return TREE[b] - TREE[a-1];
    }
};

struct node{
    int max_val,min_val;
    node(){};
    node(int a,int b){ max_val = a, min_val = b; }
};

namespace sparse_table{
    int N,sz;
    struct sample{
        vector<vector<node>> table;
        sample(vector<ll> ar){
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

    TT{
        int n;
        sl(n);
        vector<ll> ar;

        ar = vector<ll> (n+5,0);

        BIT X(n+2);
        for(int i = 1; i<=n; i++){
            sl(ar[i]);
            X.update(i,ar[i]);
        }
        X.done();

        sparse_table :: sample Y(ar) ;

//        segment_tree :: sample X(n);


        for(int i = 1; i<=n; i++){
            int ans = mx;

            int l,r,m,cur = -1;

            if(ar[i]<ar[i-1] || ar[i]<ar[i+1])  ans = 1;

            if(i>1 && ans!=1){
                l = 1, r = i-1, m, cur = -1;
                while(l<=r){
                    m = l + r >> 1;
                    ll sum = X.query(m,i-1);
                    node w = Y.query(m,i-1);

                    if(w.max_val!=w.min_val && sum>ar[i]){
                        l = m+1;
                        cur = m;
                    }
                    else r = m-1;

                }

                if(cur!=-1) ans = min(ans, abs(cur-i) );
            }

            if(i<n && ans!=1){
                l = i+1, r = n, m, cur = -1;
                while(l<=r){
                    m = l + r >> 1;
                    node w = Y.query(i+1,m);
                    ll sum = X.query(i+1,m);

                    if(w.max_val!=w.min_val && sum>ar[i]){
                        r = m - 1;
                        cur = m;
                    }
                    else l = m + 1;

                }

                if(cur!=-1) ans = min(ans, abs(cur-i) );
            }



            if(ans==mx) ans = -1;

            printf("%lld ", ans);
        }

        puts("\n");




    }


    return 0;
}

