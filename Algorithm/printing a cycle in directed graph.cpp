#include <bits/stdc++.h>
#define pb(x)                    push_back(x)
#define all(a)                   a.begin(), a.end()
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define IO                       ios::sync_with_stdio(false); cin.tie(0);cout.tie(0)
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define mx 1005
int par[mx],n,m,st,vis[mx];
vector<int> v[mx],xx;

stack<int> stk;
void dfs(int u){
    vis[u] = 1;
    for(int i:v[u]){
        if(vis[i])  continue;
        dfs(i);
    }
    stk.push(u);
}

void fn(int u,int a = 0){
        vis[u] = 1;
    for(int i:v[u]){
        par[i] = u;
        if(vis[i]==1){
            st = par[i];
            vector<int> ans;
            do{
                ans.push_back(st);
                st = par[st];
            }while(st!=par[i]);
            cout<<ans.size()<<endl;
            reverse(all(ans));
            for(ll j:ans)   cout<<j<<"\n";
            exit(0);
        }
        fn(i,u);
    }
    vis[u] = -1;
}

main(){
//read;
//IO;
cin>>n>>m;
for(int i = 0; i<m; i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
}
for(int i = 1; i<=n; i++){
    if(vis[i]==false)   dfs(i);
}

memset(vis,0,sizeof vis);

while(stk.size()){
    int u = stk.top();
    stk.pop();
    if(vis[u]!=0)   continue;
    fn(u);
}
cout<<-1;


return 0;
}
