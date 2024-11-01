#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > v;
vector<bool>vis;
stack<int>stk;

void dfs(int a){
vis[a] = true;
for(int i=0;i<v[a].size();++i){
    int child = v[a][i];
    if(!vis[child])
        dfs(child);
}

stk.push(a);
}

int main(){
int n,e;
cin>>n>>e;
v.assign(n,vector<int>());
vis.assign(n,false);
while(e--){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
}
for(int i=0;i<n;i++){
    if(!vis[i])
        dfs(i);
}
while(!stk.empty()){
    cout<<stk.top()<<" ";
    stk.pop();
}



return 0;
}
