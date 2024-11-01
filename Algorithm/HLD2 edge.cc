#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define read freopen("tst.txt","r",stdin);
typedef pair<int,int> pp;
#define mx 10001

int ara[mx][mx];
pp heavy[mx];
int n,head[mx],par[mx],pos[mx],L[mx],id,tree[4*mx];//,ara[mx];
vector<int> data;
vector<pp> v[mx],edge;

void clr(){
    id = 0;
    data.clear();
    edge.clear();
    for(int i = 0; i<=n; i++){
        v[i].clear();
        heavy[i] = {-1,-1};
        L[i] = par[i] = head[i] = pos[i] = 0;
    }

}

int dfs(int u,int a){
    L[u] = L[a]+1;
    par[u] = a;
    int H = 0,cnt = 1;
    for(auto i:v[u]){
        if(i.first==a)    continue;
        int x = dfs(i.first,u) ;
        cnt+=x;
        if(H<x){
            H = x;
            heavy[u] = i;
        }
    }
    return cnt;
}

void decompose(int u,int a,int c,int b){
    head[u] = a;
    pos[u] = ++id;
    int x = b,y = u;
    if(x>y) swap(x,y);
    data.push_back(c);
    ara[x][y] = ara[y][x] = pos[u];
    if(heavy[u].first!=-1){
        decompose(heavy[u].first,a,heavy[u].second,u);
    }
    for(auto i:v[u]){
        if(i.first==par[u] || heavy[u].first==i.first)  continue;
        decompose(i.first,i.first,i.second,u);
    }
}

void build(int n = 1,int l = 1,int r = id){
    int L = n<<1, R = L+1,m = l+r>>1;
    if(l==r){
        tree[n] = data[l];
        return;
    }
    build(L,l,m);
    build(R,m+1,r);
    tree[n] = max(tree[L],tree[R]);
}

int query(int ql,int qr,int n = 1,int l = 1,int r = id){
    int  L = n<<1,R = L+1,m = l+r>>1;
    if(r<ql || qr<l )   return -1;
    if(ql<=l && r<=qr)  return tree[n];
    return max(query(ql,qr,L,l,m),query(ql,qr,R,m+1,r));
}

void update(int ql,int qr,int val,int n = 1,int l = 1,int r = id){
    int L = 2*n,R = L+1,m = l+r>>1;
    if(r<ql || qr<l )   return;
    if(ql<=l && r<=qr){
        tree[n] = val;
        return;
    }
    update(ql,qr,val,L,l,m);
    update(ql,qr,val,R,m+1,r);
    tree[n] = max(tree[L],tree[R]);
}

int fn(int a,int b){
    int res = 0;
    for(; head[a]!=head[b]; b = par[head[b]]){
        if(L[head[a]]>L[head[b]])   swap(a,b);
        res = max(res,query(pos[head[b]],pos[b]));
    }
    if(L[a]>L[b])   swap(a,b);
    if(a==b)    return res;
    return max(res,query(pos[a]+1,pos[b]));
}


int main(){
int t;

//read;

scanf("%d",&t);

while(t--){

    scanf("%d",&n);
    clr();

    for(int i = 1; i<n; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[a].push_back(pp(b,c));
        v[b].push_back(pp(a,c));
        if(a>b) swap(a,b);
        edge.push_back(pp(a,b));
    }

    data.push_back(0);
    dfs(1,0);
    decompose(1,1,0,0);
    build();
    sort(data.begin(),data.end());

    int a,b;
    int fl;
    int q;  scanf("%d",&q);
    while(q--){
        scanf("%d",&fl);
        scanf("%d%d",&a,&b);

        if(fl==1){                  /// query
            int ans = fn(a,b);
            printf("%d\n",ans);
            continue;
        }
        a--;
        int x = ara[edge[a].first][edge[a].second];
        update(x,x,b);
        }
    }

return 0;
}
