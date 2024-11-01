/***
    articulation points -> bidirectional graph

**/
#include                <bits/stdc++.h>
#define ff              first
#define ss              second
#define pb(x)           push_back(x)
#define dbg(a)          cout<< #a <<" --> "<<(a)<<endl;
#define read            freopen("tst.txt","r",stdin)
#define write           freopen("out.txt","w",stdout)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> PP;

#define mx 10002
vector<int> v[mx];
int d[mx],low[mx],root;
bool vis[mx];
bool cut_node[mx];

static int x = 0;

void dfs(int u,int a){
    d[u] = low[u] = ++x;
    vis[u] = 1;
    int child = 0;
    for(int i:v[u]){
        if(i==a)    continue;
        child++;
        if(vis[i]){
            low[u] = min(low[u],d[i]);
            continue;
        }
        dfs(i,u);
        low[u] = min(low[u],low[i]);
        if(d[u]<=low[i] && u!=root)    cut_node[u] = true;      /// if low[i]<d[u], then it is not an articulation point
        if(u==root && child>1)         cut_node[u] = 1;
    }
    cout<<"HI "<<u<<" "<<child<<endl;
}

main(){
//read;

int n,m;
cin>>n>>m;

x = 0;

for(int i = 0; i<m; i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
}

for(int i = 1; i<=n; i++){
    root = i;
    if(vis[i]==false){
        dfs(i,0);
    }
}
int ans = 0;
cout<<endl;
for(int i = 1; i<=n; i++)
    cout<<d[i]<<" "<<low[i]<<endl;

cout<<endl;

puts("Articulation points are:");
for(int i = 1; i<=n; i++)
    if(cut_node[i]){
          cout<<i<<" ";
    }


return 0;
}


