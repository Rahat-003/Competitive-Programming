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
#define mx 100002
int ar[mx];
bool vis[mx];
vector<int> v[mx];

void dfs(int u,int p,bool &fl){
    vis[u] = true;
    for(int i:v[u]){
        if(i==p)    continue;
        if(!vis[i]) dfs(i,u,fl);
        else fl = true;
    }
}


main(){
int t,tc = 0;

int n,m;
cin>>n>>m;
for(int i = 0; i<m; i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
}

bool p = false;
dfs(1,0,p);
cout<<p<<endl;
for(int i = 1; i<=n; i++)
    cout<<vis[i]<<" ";
cout<<endl;



return 0;
}

