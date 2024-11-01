#include                <bits/stdc++.h>
#define ff              first
#define ss              second
#define pb(x)           emplace_back(x)
#define dbg(a)          cout<< #a <<" --> "<<(a)<<endl;
#define read            freopen("tst.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)
using namespace std;
typedef long long ll;
pair<int,int> pp;
pair<ll,ll> PP;
#define mx 1000002
ll check(ll n){
    return n*(n-1)/2;
}

ll fn(ll n){
    ll l = 1,r = 1e7,m,ans;
    while(l<=r){
        m = l+r>>1;
        if(check(m)>=n) ans = m,r = m-1;
        else l = m+1;
    }
    return ans;
}
int ar[mx];

main(){
//read;

ll a,b,c,d;
cin >> a >> b >> c >> d;

ll x,y;
x = fn(a),y = fn(d);
if(check(x)!=a || check(y)!=d){
    puts("Impossible");
    return 0;
}
string s;
if(!a && !b && !c && !d){
    cout<<0;
    return 0;
}
if(a==0 && b==0)    x = 0;
if(c==0 && d==0)    y = 0;

for(int i = 0; i<x; i++)    s+="0";
for(int i = 0; i<y; i++)    s+="1";

int p = 0,q = x;
ll z = x*y;
ll cnt = 0;

while(z-x>=b){
    z-=x;
    cnt++;
    swap(s[p++],s[q++]);
}

ll rem = x*(y-cnt) - b;
int id = 0;
    for(int i = cnt; i<s.size(); i++)
    if(s[i]=='1'){
        id = i;
        break;
    }
if(z!=b)    swap(s[cnt+rem],s[id]);

for(int i = 0; i<s.size(); i++){
    ar[i] = s[i]=='0';
}
for(int i = s.size()-1; i>=0; i--)
    ar[i]+=ar[i+1];
ll w = 0;
for(int i = 0; i<s.size(); i++){
    if(s[i]=='1')   w+=ar[i];
}
cout<<s<<endl;
if(w!=c){
    puts("Impossible");
    return 0;
}
cout<<s;

return 0;
}
