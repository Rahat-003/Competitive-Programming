#include <bits/stdc++.h>
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
#define case        printf("Case %d: ",++tc);
typedef long long ll;
using namespace std;


vector<ll> v,u;

void make(vector<ll> &x,ll n,bool fl){
    while(n){
        x.push_back(n%2);
        n/=2;
    }
    while(u.size()<v.size() && !fl)    u.push_back(0);
    reverse(x.begin(),x.end());
}


ll ar[64],dp[64][2][2],ara[64];

void fn(ll pos,bool f1,bool f2){
    if(pos==v.size())   return;

    ll ans = 0,lmt = 1,ini = 0,Npos = pos+1;
    if(dp[pos][f1][f2]!=-1) return;

    if(f2)  lmt = v[pos];
    if(f1)  ini = u[pos];


    for(ll i = ini; i<=lmt; i++ ){
        bool F1 = f1,F2 = f2;
        if( f1 && i>u[pos]) F1 = false;
        if( F2 && i<lmt )   F2 = false;
        ll sz = v.size()-1-pos;
        if(i)       ar[sz] = 1;
        if(i==0)    ara[sz] = 0;
        fn(Npos,F1,F2);
    }
    dp[pos][f1][f2] = 1;
}



main(){
//read;
int t,tc =0 ;
scanf("%d",&t);

while(t--){

u.clear();
v.clear();
memset(dp,-1,sizeof dp);
memset(ar,0,sizeof ar);
memset(ara,0,sizeof ara);
ll a,b;
cin>>a>>b;
if(a>b) swap(a,b);
make(v,b,1);
make(u,a,0);

for(int i = 0; i<v.size(); i++)
    ara[i] = 1;

fn(0,1,1);
ll x = 0,y = 0;

for(ll i = 0; i<63; i++){
    if(ar[i])   x|=(1ll<<i);
    if(ara[i])  y|=(1ll<<i);
}
case;
cout<<x<<" "<<y<<endl;

}

return 0;
}


