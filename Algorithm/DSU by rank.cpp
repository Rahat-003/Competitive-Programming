/*******
    Actually By Size of tree - Complexity Same
*******/
#include <bits/stdc++.h>
#define dbg(a)  cout<< #a <<" --> "<<(a)<<endl;
#define read    freopen("input.txt","r",stdin)
#define write   freopen("output.txt","w",stdout)
typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mx 200005

int par[mx],sz[mx];

int F(int a){
    if(par[a]==a)    return a;
    return par[a] = F(par[a]);
}

void merge(int a,int b){
    a = F(a);
    b = F(b);
    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);
        // sz[a] always greater or equal to sz[b]
        sz[a]+=sz[b];
        par[b] = a;
    }
}

main(){
//read;

for(int i = 1;i<mx; i++)    par[i] = i,sz[i] = 1;

int a,b;

while(cin>>a>>b)    merge(a,b);



return 0;
}
