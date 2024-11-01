#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;





#define pb push_back
#define ll long long
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define MaxN 201007
#define INF 2e9
#define INFL 2e18
#define PI acos(-1)
#define mp make_pair

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

//const ll fx[]= {+1,-1,+0,+0};
//const ll fy[]= {+0,+0,+1,-1};
//const ll fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const ll fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const ll fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const ll fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
 //v.erase(unique(v.begin(),v.end()),v.end());

ll gcd(ll a, ll b)
{
 return b ? gcd(b, a%b) : a;
}

ll bigmod(ll b,ll p,ll m)
{
    ll res=1LL%m;
    ll x=b%m;
    while(p)
    {
        if( p & 1LL )res=(res*x) % m;
        x=(x*x)%m;
        p >>=1LL;
    }
    return res;

}


void blurryface()
{
    ll n,k;
    cin>>n>>k;
    set<pii>st[k+100];
    ll arr[n+100];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<pll>v;
    for(ll i=0;i<n;i++)
    {
        ll mod=arr[i]%k;
        if(mod==0)
        {
            v.pb(mp(0ll,arr[i]));
            continue;
        }
        st[mod].insert(mp(-arr[i],i));

    }
   // cout<<"A"<<endl;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
      //  cout<<i<<endl;
        ll modval=arr[i]%k;
        if(st[modval].size()==0)
        {

            continue;
        }
        //cout<<i<<endl;
        ll dorkar=k-modval;
        if(st[dorkar].size()==0)
        {
           // cout<<i<<endl;
           if(st[modval].size()==0)
           {
               continue;
           }
            for(auto p:st[modval])
            {
                v.pb(mp((-p.first)%k,-p.first));
            }
             st[modval].clear();
            continue;
        }
        if(dorkar==modval)
        {
           // cout<<i<<endl;
            vector<ll>temp;
            for(auto p:st[dorkar])
            {
               // cout<<p.first<<endl;
                temp.pb(-p.first);
            }
            ll val=0;
            for(ll j=0;j<temp.size()-1;j+=2)
            {
                val+=(temp[j]+temp[j+1])/k;
            }
            ans+=val;
            //cout<<"A"<<val<<endl
            ll sz=st[dorkar].size();
            if(sz%2==1)
            {

                pii p= *st[dorkar].rbegin();
                v.pb(mp((-p.first)%k,-p.first));
                st[dorkar].clear();
//                st[dorkar].insert(p);
            }
            else
            {
                st[dorkar].clear();
            }

            continue;
        }
        ll mini=min((ll)st[modval].size(),(ll)st[dorkar].size());
        for(ll j=0;j<mini;j++)
        {

            ll x= -(*st[modval].begin()).first;
            ll y=  -(*st[dorkar].begin()).first;
           // cout<<x<<endl;
            ans+=(x+y)/k;
            st[modval].erase(st[modval].begin());
             st[dorkar].erase(st[dorkar].begin());
        }
        //cout<<i<<endl;
    }
    if(v.size()==0)
    {
        cout<<ans<<endl;
        return;
    }
    sort(v.begin(),v.end());
    set<pll>mst;
    ll cnt=0;
    for(ll i=0;i<v.size();i++)
    {
        ans+=(v[i].second)/k;
        mst.insert(mp(v[i].first,cnt++));
    }
    while(mst.size())
    {
        auto p1= *mst.begin();
        ll x=p1.first;
        mst.erase(p1);
        auto it=mst.lower_bound(mp(k-p1.first,0));
        if(it==mst.end())
        {
            it=mst.begin();
        }
        ll y=(*it).first;
        ans+=(x+y)/k;
        mst.erase(it);
    }
    cout<<ans<<endl;
}


int main()
{

   //  #ifndef ONLINE_JUDGE
   //    freopen("input.txt","r",stdin);
   //    freopen("output.txt","w",stdout);
  //   #endif
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        blurryface();
    }
//#ifdef LOCAL_DEFINE
  //  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
// #endif
///Before submit=>
///    *check for lleger overflow,array bounds
///    *check for n=1
}
