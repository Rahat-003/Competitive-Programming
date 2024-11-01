#include <bits/stdc++.h>

using namespace std;
vector<vector<int>>mp(101);
bool visited[101];
bool dfs(int s,int par){
visited[s]=true;
for(int i=0;i<mp[s].size();++i){
    int v=mp[s][i];
    if(!visited[v])
        dfs(v,s);
    else if(v!=par)
        return true;
}
return false;
}

int main(){

int n,e;
cin>>n>>e;
int flag=0;

while(e--){
    int a,b;
    cin>>a>>b;
    mp[a].push_back(b);
    mp[b].push_back(a);
}

for(int i=0;i<n;i++){
    if(!visited[i])
        if(dfs(i,-1)){
            cout<<"cycle"<<endl;
            flag=1;
                break;
        }
}
if(!flag)
    cout<<"no cycle"<<endl;
return 0;
}
