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
#define mx 200002
ll ar[mx];
ll tree[mx*4],lazy[4*mx],N;


void relax(ll n,ll l,ll r){

    if(lazy[n]==0)  return;

    ll L = 2*n+1,R = L+1,m = l+r>>1,last = m-l+1,right = lazy[n];

    if( (r-l+1)%2!=0 ) tree[n]+=lazy[n];


    if( (last)%2!=0)      right*=-1;

    if(l!=r){
        lazy[L]+=lazy[n];
        lazy[R]+=right;
    }
    lazy[n] = 0;
}

void update(ll ql,ll qr,ll val,ll n = 0,ll l = 0,ll r = N){
    ll L = 2*n+1,R = L+1,m = l+r>>1;
    relax(n,l,r);
    if(r<ql || qr<l )   return;
    if(ql<=l && r<=qr){
        ll x = val;
        if( (l-ql)%2)   x*=-1;
        lazy[n]+=x;
        relax(n,l,r);
        return;
    }
    update(ql,qr,val,L,l,m);
    update(ql,qr,val,R,m+1,r);
    tree[n] = tree[L]+tree[R];
}

ll query(ll ql,ll qr,ll n = 0,ll l = 0,ll r = N){
    ll L = 2*n+1,R = L+1,m = l+r>>1;
    relax(n,l,r);
    if(r<ql || qr<l)    return 0;
    if(ql<=l && r<=qr)  return tree[n];
    return query(ql,qr,L,l,m) + query(ql,qr,R,m+1,r);
}

main(){
int t,tc = 0;
scanf("%lld%lld",&N,&t);
for(ll i = 1; i<=N; i++){
    scanf("%lld",ar+i);
    ar[i]+=ar[i-1];
}

for(ll i = 0; i<t; i++){
    ll type,l,r,x;
    scanf("%lld%lld%lld",&type,&l,&r);
        --l,r--;
    if(type<3){
        scanf("%lld",&x);
        if(type==1) update(l,r,x);
        else{
            x*=-1;
            update(l,r,x);
        }
        continue;
    }
    ll y = query(l,r);
    ll ans = ar[r+1]-ar[l] + y;

    printf("%lld\n",ans);
}


return 0;
}

