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







main(){
//read;
//write;
    TT{
        int n;
        si(n);
        string s;
//        cin >> s;
//        s = " " + s;
//        n = SZ(s);
        int pref[n+2][26];
        ms(pref,0);

        for(int i = 1; i<=n; i++){
            int x;
            si(x);
            pref[i][x]++;
            for(int j = 0; j<26; j++){
                pref[i][j]+=pref[i-1][j];
            }
        }


        int q;
        si(q);
        int ans = 0;

        while(q--){
            int l,r;
            sii(l,r);
            if((r-l)&1) continue;

            if(l==r){
                ans++;
                continue;
            }

            int mid = l + (r-l)/2;
            int a = l,b = mid - 1,c = mid, d = r;

            int flag1 = 1,flag2 = 1,cnt = 0;

            for(int i = 0; i<26; i++){
                int x = pref[b][i] - pref[a-1][i];
                int y = pref[d][i] - pref[c-1][i];

                if(x==y)    continue;
                if(cnt==0 && y-x==1)  cnt++;
                else flag1 = 0;

            }


            a = l,b = mid,c = mid+1,d = r;
            cnt = 0;

            for(int i = 0; i<26; i++){
                int x = pref[b][i] - pref[a-1][i];
                int y = pref[d][i] - pref[c-1][i];

                if(x==y)    continue;
                if(cnt==0 && x-y==1)  cnt++;
                else flag2 = 0;
            }

            if(flag1 || flag2)  ans++;

        }
        case;
        printf("%d\n",ans);

    }







    return 0;
}


