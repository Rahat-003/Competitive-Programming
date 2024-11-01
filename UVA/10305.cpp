#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > v(105);
vector<bool>vis;
stack<int>stk;
void dfs(int a){
vis[a] = true;

for(int i=0;i<v[a].size();i++){
    int child = v[a][i];
    if(!vis[child])
        dfs(child);
}

stk.push(a);
}

int main(){
int n,e;
//int c=0;
while(cin>>n>>e){
for(int i=0;i<105;i++)
    v[i].clear();

    if(n==0 && e==0)
        break;
    while(e--){
            int nn,ee;
            cin>>nn>>ee;
    v[nn].push_back(ee);
    }
vis.assign(n+1,false);
for(int i=1;i<=n;i++)
    if(!vis[i])
    dfs(i);

while(!stk.empty()){
    cout<<stk.top()<<" ";
    stk.pop();
}
cout<<endl;
}

return 0;
}
