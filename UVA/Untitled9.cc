#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
#define mx 1000005
bool ara[mx];
vector<ll> v;// = {5,4,3,1};
ll ar[mx],br[mx];
ll go(ll n){
    return n*(n-1)>>1;
}
ll fn(ll n){
//    if(n==0)    return 1;
    ll l = 0,r = 1e9,m,x = 0;
    while(l<=r){
        m = l+r>>1;
        ll y = go(m);
        if(y>=n)    r = m-1,x = m;
        else    l = m+1;
    }
    return x;
}

bool check(string s,ll p,ll q,ll r,ll t){
        ll a = 0,d = 0,b = 0,c = 0;
    for(int i = 0; i<s.size(); i++){
        ar[i] = s[i]=='1';
        br[i] = !ar[i];
        if(ar[i]==1)  d++;
        else a++;
    }
    a = a*(a-1)>>1;
    d = d*(d-1)>>1;

    ll x = 0,y = 0;
    for(ll i = s.size()-1; i>=0 ; i--){
        br[i]+=x;
        ar[i]+=y;
        x = br[i];  y = ar[i];
    }
    for(ll i = 0; i<s.size(); i++){
        if(s[i]=='0')   b+=ar[i+1];
        else c+=br[i+1];
    }
    return (p==a && q==b && r==c && t==d);
}

main(){

ll a,b,c,d;
scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
if(!a && !b && !c && !d){
    puts("0");
    return 0;
}

ll p = fn(a),q = fn(d);

if(go(p)!=a || go(q)!=d){
    puts("Impossible");
    return 0;
}

//cout<<p<<" "<<q<<endl;
/*
if(p*q!=b+c && p*q && b+c){
    puts("Impossible");
    return 0;
}*/
if(p==0)    p = 1;
if(q==0)    q = 1;
if(a==b && b==c && c==0)    p = 0;
if(b==c && c==d && d==0)    q = 0;

ll rem = b;

for(ll i = 0; i<p; i++){
    if(rem>=q){
        v.push_back(q);
        rem-=q;
    }
    else{
        v.push_back(rem);
        rem = 0;
    }
}

sort(v.rbegin(),v.rend());
ll zero = 0,one = 0;

for(ll i = 0; i<v.size(); i++){
    if(i)   one+=v[i-1]-v[i];
    else    one = q-v[i];
    ara[zero+one] = true;
    zero++;
}
string ans;
for(ll i = 0; i<p+q; i++){
    if(ara[i])   ans.push_back('0');
    else ans.push_back('1');
}

//cout<<ans<<endl;

if(check(ans,a,b,c,d)==false){
    puts("Impossible");
    return 0;
}
cout<<ans<<endl;

return 0;
}
