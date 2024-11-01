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


typedef long long  ll;
typedef __uint128_t LL;

vector<ll> prime2 = {2,3,5,7,11,13,17,19,23,29,31,37},w,prime = {0,2,3,5,7};

/*******
	Don't cast like this (LL)(x*x)%m or ((LL)(x*x))%m , it will give 999999999999999989 as non prime
	Simply use (LL)x*x%m
********/

ll Fn(ll b,ll p,ll m){
    if(p==0)    return 1;
    if(p==1)    return b%m;
    ll x;
    if(p%2==0){
        x = Fn(b,p/2,m);
        return (LL)x*x%m;
    }
    x = Fn(b,p-1,m)%m;
    return (LL)x*b%m;
}


bool check(ll a,ll s,ll d,ll n){
    ll x = Fn(a,d,n);
    if(x==1 || x==n-1)  return true;

    for(ll i = 1; i<s; i++){
        x = (LL)x*x%n;
        if(x==n-1)  return true;
    }
    return false;
}

bool Miller(ll n){
    if(n<4) return n==2 || n==3;
    if(n%2==0)  return false;

    ll s = 0,d = n-1;
    while(d%2==0){
        s++;
        d/=2;
    }

    for(ll i:prime2){
    	if(n==i)	return true;
        ll a = i;
        if(!check(a,s,d,n)) return false;
    }
    return true;

}

bool flag = false;

ll ans = -1;

void fn(ll pos,bool fl,ll n){
    if(flag)    return;
    if(pos==w.size()){
        if(Miller(n)){
            flag = true;
            ans = n;
        }
        return;
    }
    ll lmt = 4;
    if(fl){
        lmt = lower_bound(prime.begin(),prime.end(),w[pos]) - prime.begin();
        if(lmt==prime.size()){
            fl = false;
            --lmt;
        }
        else{
            if(prime[lmt]>w[pos]){
            fl = false;
            --lmt;
            }
        }
    }

    for(ll i = lmt; i>=0; i--){
        bool F = fl;
        if(n && !i) continue;
        if(pos && pos==w.size()-1 &&(i==1 || i==3) )   continue;

        if( (fl && i<lmt) ) F = false;

        fn(pos+1,F,n*10+prime[i]);
    }


}

void make(ll n){
    while(n){
        w.push_back(n%10);
        n/=10;
    }
    reverse(w.begin(),w.end());
}

main(){
int t,tc = 0;
scanf("%d",&t);
while(t--){
    ll n;
    scanf("%lld",&n);
    flag = false;   ans = -1;
    make(n);
    fn(0,1,0);
    case;
    printf("%lld\n",ans);
    w.clear();
}

return 0;
}
