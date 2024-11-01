#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)

vector<ll> v,u;

ll fn(ll pos,bool f1,bool f2){
    if(pos==v.size())   return 1;

    ll ans = 0,lmt = 9,ini = 0,Npos = pos+1;

    if(f2)  lmt = v[pos];
    if(f1)  ini = u[pos];


    for(ll i = ini; i<=lmt; i++ ){
        bool F1 = f1,F2 = f2;
        if( f1 && i>u[pos]) F1 = false;
        if( F2 && i<lmt )   F2 = false;

        ans+=fn(Npos,F1,F2);
    }

    return ans;
}

void make(vector<ll> &x,ll n,bool fl){
    while(n){
        x.push_back(n%10);
        n/=10;
    }
    while(u.size()<v.size() && !fl)    u.push_back(0);
    reverse(x.begin(),x.end());
}

int main(){
int t,tc = 0;
ll a,b;
scanf("%lld%lld",&a,&b);

make(v,b,1);
make(u,a,0);

int ans = fn(0,1,1);
cout<<ans<<endl;


return 0;
}
