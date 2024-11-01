#include <bits/stdc++.h>
#define pb(x)                    push_back(x)
#define all(a)                   a.begin(), a.end()
#define dbg(a)                   cout<< #a <<" --> "<<(a)<<endl;
#define IO                       ios::sync_with_stdio(false); cin.tie(0);cout.tie(0)
#define read                     freopen("tst.txt","r",stdin)
#define write                    freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;

#define mx 100005
int ar[mx],par[mx],vis[mx];
vector<int> v[mx];
int n,m,sz;

int tree[mx][22],L[mx];

void dfs(int u,int a){
    L[u] = L[a] + 1;
    vis[u] = 1;
    par[u] = a;
    for(int i:v[u]){
        if(vis[i] || i==a)  continue;
        dfs(i,u);
    }
}

void build(){
    dfs(1,0);
    sz = log2(n);

    for(int i = 1; i<=n; i++)
        tree[i][0] = par[i];

    for(int i = 1; i<=20; i++){
        for(int j = 1; j<=n; j++){
            if(tree[j][i-1]==-1)    continue;
            tree[j][i] = tree[tree[j][i-1]][i-1];
        }
    }
}

int query(int a,int b){
    if(L[a]>L[b])   swap(a,b);
    for(int i = 20; i>=0; i--){
        if(L[b] - (1<<i)>=L[a]) b = tree[b][i];
    }
    for(int i = 20; i>=0; i--){
        if(tree[b][i]!=-1 && tree[b][i]!=tree[a][i])    a = tree[a][i],b = tree[b][i];
    }
    if(a==b)    return a;
    return par[a];
}
int fn(int p,int q,int d){
    int a = query(p,q);
    int x,y;
    x = L[p] - L[a],y = L[q] - L[a];
    if(d==x)    return a;
    if(d>x) y-=d-x;
    else q = p,y = d;
    for(int i = 20; i>=0; i--)
        if(tree[q][i]!=-1 && (1<<i)<=y) q = tree[q][i],y-=1<<i;
    return q;
}

main(){
//read;

cin>>n;

for(int i = 1 ; i<n; i++){
    int a,b;    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
}
    memset(tree,-1,sizeof tree);
build();
int a,b,c;

while(cin>>a>>b>>c)
    cout<<fn(a,b,c)<<endl;


return 0;
}
