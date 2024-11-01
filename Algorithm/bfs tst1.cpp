#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>v(1001);
bool vis[1001];
void bfs(int s){
    queue<int>q;
    q.push(s);
    memset(vis,false,sizeof(vis));
    vector<int>lvl(1001,0);
    vis[s]=true;
    lvl[s]=1;
    while(q.empty()==false){
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        for(int i=0;i<v[u].size();++i){
            int child = v[u][i];
            if(vis[child]==false){
                vis[child]=true;
                q.push(child);
                lvl[child]= lvl[u]+1;
            }
        }
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
        cout<<i<<" "<<lvl[i]<<endl;

}

int main(){
    cin>>n;
    int e;
    cin>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

bfs(1);



return 0;
}
