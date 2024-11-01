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
#define mx 150003
bool vis[mx];
int par[mx];
vector<int> v[mx];

int F(int a){
    if(par[a]!=a)   par[a] = F(par[a]);
    return par[a];
}

void merge(int a,int b){
    int x = F(a);
    int y = F(b);

    if(x!=y){
        par[y] = x;
        v[x].push_back(y);
    }
}

void dfs(int a){
    cout<<a<<" ";
    vis[a] = true;
    for(int i:v[a]){
        if(i==a)    continue;
        if(!vis[i])
            dfs(i);
    }
}

main(){

int t,tc = 0;
for(int i = 1; i<mx; i++)   par[i] = i;

int n,q;
cin>>n>>q;
for(int i = 0; i<q; i++){
    int a,b;
    cin>>a>>b;
    merge(a,b);
}
cout<<endl;
for(int i = 1; i<=5; i++)   cout<<i<<" "<<par[i]<<endl;

dfs(F(1));
cout<<endl;

return 0;
}
