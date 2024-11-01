#include <cstdio>
#include <queue>
#include <vector>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define mx 501
#define MX 100000000
typedef pair<ll,ll> pp;

vector<ll> v[mx],par[mx];

ll cost[mx][mx],s,d,n,m,L[mx];
//bool vis[mx][mx];

void go(int x,int y){
    if(x==s)    return;
    for(int i:par[x]){
        cost[i][x] = MX;
        go(i,x);
    }
}


void fn(){
    for(ll i = 0; i<n; i++)    L[i] = MX;
    priority_queue<pp,vector<pp>,greater<pp> > pq;
    pq.push(pp(0,s));

    while(pq.size()){
        pp u = pq.top();
        pq.pop();
        ll x = u.second,y = u.first;
        for(ll i = 0; i<v[x].size(); i++){
            ll child = v[x][i],w = cost[x][child];

            if(L[child]<y+w)    continue;
            if(L[child]>y+w)                par[child].clear();


            L[child] = w+y;
            pq.push(pp(L[child],child));
            par[child].push_back(x);
        }
    }
//    par[s].clear();
    go(d,d);
}



ll dijkstra(){
    for(ll i = 0; i<n; i++)    L[i] = MX;
    priority_queue<pp,vector<pp>,greater<pp> > pq;
    pq.push(pp(0,s));

    while(pq.size()){
        pp u = pq.top();
        pq.pop();
        ll x = u.second,y = u.first;
        for(ll i = 0; i<v[x].size(); i++){
            ll child = v[x][i],w = cost[x][child];
            if(L[child]>w+y){
                L[child] = w+y;
                pq.push(pp(L[child],child));
            }
        }
    }
    if(L[d]==MX)    return -1;
    return L[d];
}

main(){

//read;

while(2==scanf("%lld%lld",&n,&m)){
    if(n==0 && m==0)    break;
    scanf("%lld%lld",&s,&d);

    for(ll i = 0; i<n; i++){
        par[i].clear();
        v[i].clear();
    }
    for(ll i = 0; i<=n; i++)
        for(ll j = 0; j<=n; j++) cost[i][j] = MX;

    for(ll i = 0,a,b,c; i<m; i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        v[a].push_back(b);
        cost[a][b] = c;
    }
    fn();
    ll ans = dijkstra();
    printf("%lld\n",ans);

}


return 0;
}
