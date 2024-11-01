#include <bits/stdc++.h>
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;

#define mx 100002
bool vis[mx];
vector<int> v[mx],ans;

void go(int a,int b){
    v[a].push_back(b);
    v[b].push_back(a);
}

void dfs(int u){
    vis[u] = 1;
    ans.push_back(u);
    for(int i:v[u]){
        if(vis[i])  continue;
        dfs(i);
    }
}

main(){
//read;
int n;
cin>>n;
for(int i = 0; i<n-2; i++){
    int a,b,c;
    cin>>a>>b>>c;
    go(a,b);
    go(b,c);
    go(c,a);
}

dfs(1);
for(int i:ans)
    cout<<i<<" ";

return 0;
}
