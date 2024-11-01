#include <bits/stdc++.h>

using namespace std;
vector<vector<int>>mp(1001);
bool visited[1001];
stack<int>stk;

void dfs(int s){
visited[s]=true;
for(int i=0;i<mp[s].size();++i)
    if(!visited[mp[s][i]])
        dfs(mp[s][i]);

}

void topology(int s){
visited[s]=true;
for(int i=0;i<mp[s].size();++i)
    if(!visited[mp[s][i]])
        topology(mp[s][i]);
stk.push(s);

}
int main(){

int n,e;
while(cin>>n>>e){
    while(e--){
    int a,b;
    cin>>a>>b;

    mp[a].push_back(b);
    mp[b].push_back(a);
    }
    memset(visited,false,sizeof visited);
    for(int i=0;i<n;i++){
        if(!visited[i])
            topology(i);
    }
    int cnt=0;
    memset(visited,false,sizeof visited);

    while(!stk.empty()){
        int u=stk.top();
        stk.pop();
        if(!visited[u])
        {
            dfs(u);
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

return 0;
}
