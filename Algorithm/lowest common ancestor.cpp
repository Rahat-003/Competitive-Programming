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
#define mx 200004

vector<int> v[mx];

int L[mx],par[mx],tr[mx][21];

int n;

void dfs(int u,int a){
    L[u] = L[a]+1;
    par[u] = a;
    for(int i:v[u]){
        if(i==a)  continue;
        dfs(i,u);
    }
}

void build(){
    int sz = log2(n);
    for(int i = 1; i<=n; i++)   tr[i][0] = par[i];
    for(int i = 1; i<=sz; i++){
        for(int j = 1; j<=n; j++){
            if(tr[j][i-1]!=0)
            tr[j][i] = tr[tr[j][i-1]][i-1];
        }
    }
}

int LCA(int a,int b){
    /// LCA of node a and b
    if(L[a]>L[b])   swap(a,b);
    int sz = log2(n);
    for(int i = sz; i>=0; i--)  if(L[b]-(1<<i)>=L[a])   b = tr[b][i];
    for(int i = sz; i>=0; i--)  if(tr[a][i]!=0 && tr[a][i]!=tr[b][i]) a = tr[a][i],b = tr[b][i];
    if(a==b)    return a;
    return par[a];
}

int dist(int a,int b){
    if(L[a]>L[b])   swap(a,b);
    int p = LCA(a,b);
    return L[a]+L[b]-2*L[p];
}


main(){
int t,tc = 0;

scanf("%d",&n);

for(int i = 1; i<n; i++){
    int a,b;
    scanf("%d%d",&a,&b);
    v[a].push_back(b);
    v[b].push_back(a);
}
dfs(1,0);
build();

int a,b;
while(cin>>a>>b)    cout<<LCA(a,b)<<" "<<dist(a,b)<<endl;

return 0;
}

