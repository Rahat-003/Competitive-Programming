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
#define mx 100005
bool vis[mx];
vector<int> v[mx];
deque<int> dq;

void dfs(int a,int u){
    vis[a] = true;
    for(int i:v[a]){
        if(i==u)    continue;
        if(!vis[i])
            dfs(i,a);
    }
    dq.push_back(a);
}


int main(){

int n,m;

scanf("%d%d",&n,&m);

for(int i = 0; i<m; i++){
    int a,b;
    scanf("%d%d",&a,&b);
    v[a].push_back(b);
}

for(int i = 1; i<=n; i++){
    if(!vis[i]) dfs(i,0);
}

while(dq.size()){
    cout<<dq.back()<<" ";
    dq.pop_back();
}

return 0;
}
