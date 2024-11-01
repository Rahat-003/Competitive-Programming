#include                        <bits/stdc++.h>
#include                        <ext/pb_ds/assoc_container.hpp>
#define lb                      lower_bound
#define ub                      upper_bound
#define fe(x)                   (*(x.begin()))
#define le(x)                   (*(x.rbegin()))
#define pb                      push_back
#define load(node,n)            bool operator < (const node &n) const
#define fbo(x,id)               (*(x.find_by_order(id)))
#define ook(y)                  order_of_key(y)
#define all(x)                  (x).begin(),(x).end()
#define FOR(i,n)                for(int i = 1; i<=n; i++)
#define REP(i,n)                for(int i = 0; i<n;  i++)
#define SZ(x)                   (int)x.size()
#define TT                      long long TC;  scanf("%lld",&TC);  while(TC--)
#define write                   freopen("input.txt","w",stdout)
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
using                           namespace __gnu_pbds;
using                           namespace std;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;





main(){

write;

    puts("1");

    int n,m,p,q;

    cin >> n >> m;
    q = 0;
    p = n*m;
    cout << n << " " << m << " " << p << " " << q << endl;

    cout << "1 1 " << n << " " << m<<endl;

    for(int i = 0; i<8; i++){
        ll x = rand()%3465 + rand()%45754687 + rand()%679687912 + rand()%5682354345 ;
        x+=2e6;
        ll y = 1e9;
        x = min(x,y);
        if(x==1e9)  x-=rand()%568243 - rand()%456723;
        cout << x << " ";
    }

    cout << endl;

    for(int a = 1; a<=n ; a++){
        for(int b = 1; b<=m ; b++){
            int x = rand()%345 + rand()%23453246 + rand()%4356457 + rand()%345321;
            int y = rand()%346643 + rand()%234325 + rand()%23144325;
            x%=n;
            x++;
            y%=m;
            y++;
            cout << a << " " << b << " " << x << " " << y << " " << (x+y)%3454 + 8632 << endl;
        }
    }



return 0;
}
