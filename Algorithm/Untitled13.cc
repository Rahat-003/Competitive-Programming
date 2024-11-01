#pragma                         GCC optimize("O3","unroll-loops")
#include                        <bits/stdc++.h>
//#include                        <ext/pb_ds/assoc_container.hpp>
//#define lb                      lower_bound
//#define ub                      upper_bound
//#define fe(x)                   (*(x.begin()))
//#define le(x)                   (*(x.rbegin()))
//#define pb                      push_back
//#define load(node,n)            bool operator < (const node &n) const
//#define fbo(x,id)               (*(x.find_by_order(id)))
//#define ook(y)                  order_of_key(y)
//#define all(x)                  (x).begin(),(x).end()
#define si(a)                   scanf("%d",&a)
#define sii(a,b)                scanf("%d %d",&a,&b)
#define siii(a,b,c)             scanf("%d %d %d",&a,&b,&c)
//#define sl(a)                   scanf("%lld",&a)
//#define sll(a,b)                scanf("%lld %lld",&a,&b)
//#define slll(a,b,c)             scanf("%lld %lld %lld",&a,&b,&c)
//#define rep(i,a,b)              for(ll i = a; i<=b;  i++)
//#define un(x)                   x.erase(unique(all(x)), x.end())
//#define TT                      long long TC;  scanf("%lld",&TC);  for(ll tc = 1; tc<=TC; tc++)
//#define read                    freopen("input.txt","r",stdin)
//#define write                   freopen("output.txt","w",stdout)
//#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
//#define SZ(x)                   (int)x.size()
//#define ff                      first
//#define ss                      second
//#define FF                      fflush(stdout);
//#define infi                    0x3f3f3f3f
//#define infl                    0x3f3f3f3f3f3f3f3f
//#define ms(AR,x)                memset(AR,x,sizeof AR);
//#define case                    printf("Case %lld: ",tc);
//using                           namespace __gnu_pbds;
using                           namespace std;
//typedef                         long long ll;
//typedef                         pair<ll,ll> pll;


typedef                         pair<int,int> pii;
typedef                         pair<int,pii> ipp;

class Solution {
public:

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    set<ipp> st;
    vector<vector<int>> vis,vis2;
    int cnt,n,m,flag;
    queue<pii> q;

    bool check(int x,int y){
        if(x<0 || x>=n || y<0 || y>=m)  return 0;
        return 1;
    }

    void bfs(auto &v){
//        cout << endl;

//        cout << "HOLA " << cnt << " " << flag << endl;

        while((int)q.size()){
            pii u = q.front();
            q.pop();
            if(vis[u.first][u.second])  continue;
//            cout << u.first << " " << u.second << " " << v[u.first][u.second] << endl;
            vis[u.first][u.second] = 1;
            vis2[u.first][u.second] = 1;
            cnt++;
            for(int i = 0; i<4; i++){
                int nx = dx[i] + u.first;
                int ny = dy[i] + u.second;

//                if(check(nx,ny)){
//                    cout << "Child " << nx << " " << ny << " " << v[nx][ny] << " " << vis[nx][ny] << endl;
//                }

                if(check(nx,ny)==0 || vis[nx][ny]) continue;
                if(v[nx][ny]<flag){
                    q.push(pii(nx,ny));
                }
                else if(vis2[nx][ny]==0){
                    st.insert(ipp(v[nx][ny],pii(nx,ny)));
                    vis2[nx][ny] = 1;
                }
            }
        }


//        while(q.size()) q.pop();
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int> ans;
        vector<pii> query;

        n = grid.size(),m = grid[0].size();
        cnt = 0;
        for(int i = 0; i<n; i++){
            vis.push_back(vector<int> (m+2,0));
            vis2.push_back(vector<int> (m+2,0));
        }
        for(int i = 0; i<(int)queries.size(); i++){
            query.push_back(pii(queries[i],i));
        }
        ans = vector<int> (query.size(),0);
        sort(query.begin(),query.end());
        st.insert(ipp(grid[0][0],pii(0,0)));
        vis2[0][0] = 1;

        for(auto i:query){
            while((int)st.size()){
                auto u = *(st.begin());
                if(u.first<i.first){
                    q.push(u.second);
                    st.erase(u);
                }
                else break;
            }
            flag = i.first;
            bfs(grid);
            ans[i.second] = cnt;
        }


        return ans;
    }
};




main(){
//read;



    int n,m,q;
    siii(n,m,q);

    vector<vector<int>> grid;

    for(int i = 0; i<n; i++){
        grid.push_back(vector<int> (m,0));
        for(int j = 0; j<m; j++){
            si(grid[i][j]);
        }
    }

    vector<int> v,query;

    for(int i = 0; i<q; i++){
        int x;
        si(x);
        query.push_back(x);
    }

    Solution X;
//    = (grid,query);
    v = X.maxPoints(grid,query);

    for(int i:v)
        cout << i << " ";
    cout << endl;


    return 0;
}


