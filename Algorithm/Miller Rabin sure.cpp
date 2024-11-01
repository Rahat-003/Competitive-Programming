#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
using namespace std;
#define pi acos(-1)

typedef long long  ll;
typedef __uint128_t LL;
vector<ll> prime = {2,3,5,7,11,13,17,19,23,29,31,37};

/*******
	Don't cast like this (LL)(x*x)%m or ((LL)(x*x))%m , it will give 999999999999999989 as non prime
	Simply use (LL)x*x%m
********/

ll fn(ll b,ll p,ll m){
    if(p==0)    return 1;
    if(p==1)    return b%m;
    ll x;
    if(p%2==0){
        x = fn(b,p/2,m);
        return (LL)x*x%m;
    }
    x = fn(b,p-1,m);
    return (LL)x*b%m;
}


bool check(ll a,ll s,ll d,ll n){
    ll x = fn(a,d,n);
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
    
    for(ll i:prime){
    	if(n==i)	return true;
        ll a = i;
        if(!check(a,s,d,n)) return false;
    }
    return true;
    
}   


int main(){
int t,tc = 0;
ll n;

while(cin>>n)	cout<<Miller(n)<<endl;


return 0;
}

