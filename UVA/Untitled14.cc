#include                <bits/stdc++.h>
#define ff              first
#define ss              second
#define pb(x)           emplace_back(x)
#define dbg(a)          cout<< #a <<" --> "<<(a)<<endl;
#define read            freopen("tst.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> PP;

#define mx 1001

const ll P = 7+1e9;

ll U[mx][mx],ar[mx][mx],ara[mx][mx],n;

void mult(ll a[mx][mx],ll b[mx][mx],ll c[mx][mx]){

    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<n; j++){
            ll x = 0;
            for(ll k = 0; k<n; k++){
                x+=(a[i][k]*b[k][j]);
                x%=P;
            }
            ara[i][j] = x;
        }
    }
    for(ll i = 0; i<n; i++)
        for(ll j = 0; j<n; j++)
            c[i][j] = ara[i][j];
}
ll res[mx][mx];

void fn(ll n){

    while(n){
        if(n%2)   mult(U,ar,U);
        mult(ar,ar,ar);
        n/=2;
    }

}



main(){
//read;

n = 5;

for(ll i = 0; i<n; i++)
    U[i][i] = 1;

for(ll i = 0; i<n; i++){
    for(ll j = 0; j<n; j++){
        ll x = 1+rand()%9;
        ar[i][j] = x;
    }
}

///*

for(ll i = 0; i<n; i++){
    for(ll j = 0; j<n; j++)
        cout<<ar[i][j]<<" ";
    cout<<endl;
}

//*/
cout<<endl;

ll z = 1e18;

fn(z);

for(ll i = 0; i<n; i++){
    for(ll j = 0; j<n; j++)
        cout<<U[i][j]<<" ";
    cout<<endl;
}

return 0;
}


