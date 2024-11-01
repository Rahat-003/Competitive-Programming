#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>v(1001);

int n;
void bfs(int s){
queue<int>q;
bool visited[1001];
memset(visited,false,sizeof(visited));
visited[s]=true;
q.push(s);
vector<int>level(1001,0);
level[s]=1;
while(!q.empty()){
    int u=q.front();
    cout<<u<<" ";
    q.pop();
    for(int i=0;i<v[u].size();i++){
        int child=v[u][i];
        if(!visited[child]){
            visited[child]=true;
            level[child]=level[u]+1;
            q.push(child);
}
}
}
cout<<endl;
for(int i=1;i<=n;i++)
    cout<<i<<" "<<level[i]<<endl;

}
int main(){
cin>>n;
int child;
cin>>child;
while(child--){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
}

bfs(1);

return 0;
}
