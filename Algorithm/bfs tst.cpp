#include <bits/stdc++.h>
using namespace std;
vector <vector<int>> v(1001);
int n;
void bfs(int s){
    bool vis[1001];
    memset(vis,false,sizeof(vis));
    vis[s]=true;
    queue<int>q;
    q.push(s);
    vector<int>level(1001,0);
    level[s]=1;
    while(q.empty()==false){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int i=0;i<v[u].size();++i){
                int child=v[u][i];
            if(!vis[child]){
                vis[child]=true;
                level[child]=level[u]+1;
                q.push(child);

            }
        }
    }
    cout<<endl;
for(int i=s;i<=n;i++){
    cout<<i<<" "<<level[i]<<endl;
}



}

int main(){

cin>>n;
int edge;
cin>>edge;
while(edge--){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
}
bfs(1);


return 0;
}
