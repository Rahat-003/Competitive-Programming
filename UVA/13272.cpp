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
#define case                    printf("Case %lld:\n",tc);
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;

#define mx 100005

string s;

int n,nxt[mx],dp[mx];

bool fn(int i,int j){
    i++;
    if(i+dp[i]==j)  return 1;
    return 0;
}

main(){
//read;



TT{

    cin>>s;
    s = " " + s;
    n = SZ(s);
    memset(dp,0,sizeof dp);
    memset(nxt,-1,sizeof nxt);

    int a = -1,b = -1,c = -1,d = -1;

    stack<int> st[4];
    for(int i = n - 1; i ; i--){
        if(s[i]==')')   st[0].push(i);
        if(s[i]=='('){
            if(SZ(st[0]))   nxt[i] = st[0].top(),st[0].pop();
        }


        if(s[i]=='}')   st[1].push(i);
        if(s[i]=='{'){
            if(SZ(st[1]))   nxt[i] = st[1].top(),st[1].pop();
        }

        if(s[i]==']')   st[2].push(i);
        if(s[i]=='['){
            if(SZ(st[2]))   nxt[i] = st[2].top(),st[2].pop();
        }

        if(s[i]=='>')   st[3].push(i);
        if(s[i]=='<'){
            if(SZ(st[3]))   nxt[i] = st[3].top(),st[3].pop();
        }
    }

    for(int i = n-1 ; i; i--){
        if(nxt[i]==-1)  continue;
        int r = nxt[i];
        if(fn(i,r)) dp[i] = r - i + 1 + dp[r+1];
    }

/*
555
(((){)}[]<>)

(<()>)

*/


    case;
    for(int i = 1; i<n; i++){
        printf("%d\n",dp[i]);
    }
}





return 0;
}

