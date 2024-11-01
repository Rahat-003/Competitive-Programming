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

int N;

struct node{
    int max_val,min_val,sum;
    node(){};
    node(int a,int b,int c){    max_val = a;    min_val = b;  sum = c; }
};

struct segment_tree{
    vector<node> TREE;  vector<int> lazy;
    segment_tree(){
        TREE = vector<node> (4*N+2,node(0,0,0));
        lazy = vector<int> (4*N+2,0);
    }

    void relax(int n,int l,int r){
        int L = n<<1,R = L+1,m = l+r>>1;
        if(lazy[n]==0)  return;
        TREE[n].sum+=(r-l+1)*lazy[n];
        TREE[n].max_val+=lazy[n];
        TREE[n].min_val+=lazy[n];
        if(l!=r)    lazy[L]+=lazy[n],lazy[R]+=lazy[n];
        lazy[n] = 0;
    }
    void update(int ql,int qr,int x,int n = 1,int l = 1,int r = N){
        relax(n,l,r);
        int L = n<<1,R = L+1, m = l+r>>1;
        if(r<ql || qr<l)    return;
        if(ql<=l && r<=qr){
            lazy[n]+=x;
            relax(n,l,r);
            return;
        }
        update(ql,qr,x,L,l,m);
        update(ql,qr,x,R,m+1,r);
        TREE[n].sum = TREE[L].sum + TREE[R].sum;
        TREE[n].max_val = max(TREE[L].max_val,TREE[R].max_val);
        TREE[n].min_val = min(TREE[L].min_val,TREE[R].min_val);
    }
    node query(int ql,int qr,int n = 1,int l = 1,int r = N){
        relax(n,l,r);
        int L = n<<1,R = L+1, m = l+r>>1;
        if(r<ql || qr<l)    return node(-1000000000,1000000000,0);
        if(ql<=l && r<=qr)  return TREE[n];
        node a = query(ql,qr,L,l,m),b = query(ql,qr,R,m+1,r);
        return node(max(a.max_val,b.max_val),min(a.min_val,b.min_val),a.sum+b.sum);
    }
};




main(){
//read;


N = 100;

segment_tree X;

while(1){
    int fl,l,r;
    cin>>fl>>l>>r;
    if(fl==1){
        //update
        int x;
        cin>>x;
        X.update(l,r,x);
        continue;
    }
    node p = X.query(l,r);
    cout<<p.max_val<<" "<<p.min_val<<" "<<p.sum<<endl;
}


return 0;
}
