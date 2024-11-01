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


    int n,k;

void integerToBinary(int x)
{
    string a="";
    while(x!=0)
    {
        if(x%2)
        {
            a.pb('1');
        }
        else
        {
            a.pb('0');
        }
        x=x/2;
    }
   // reverse(a.begin(),a.end());
    while(a.size()<k)
    {
        a.pb('0');
    }
    reverse(a.begin(),a.end());
    cout<<a<<" ";
}

void blurryface()
{
    cin>>n>>k;
    vector<int>v;
    int maxval=(1<<k);
    for(int i=0;i<n;i++)
    {
        int x;
        x= rand()%maxval;
        v.pb(x);
    }
    for(int i=0;i<v.size();i++)
    {
        integerToBinary(v[i]);
//        cout<<v[i]<<" ";
    }
    cout<<endl;
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            for(int x=0;x<(1<<k);x++)
            {
                int val = (v[i] ^ x) & (v[j] ^ x);
//                cout<<v[i]<<" "<<v[j]<<" "<<val<<endl;
                ans=max(ans,val);
            }
        }
    }
    cout<<ans<<endl;
}




int main(){
//read;
    blurryface();
    return 0;
}


