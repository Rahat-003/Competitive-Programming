#include <bits/stdc++.h>
using namespace std;
int n,cnt;
vector<vector<int> > v;
vector<bool>vis;
void dfs(int s){
    cnt++;
    vis[s]=true;
    for(int i=0;i<v[s].size();i++){
        int child = v[s][i];
        if(!vis[child])
            dfs(child);
    }




}
int main(){

int t;
cin>>t;
while(t--){
    int e,c;
    cnt=0;
    cin>>n>>e>>c;
    v.assign(n+1,vector<int>());
    vis.assign(n+1,false);
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    while(c--){
        int a;
        cin>>a;
        if(!vis[a])
            dfs(a);
    }
    cout<<cnt<<endl;

    /*for(int i=0;i<n+1;i++)
        v[i].clear();*/
    v.clear();
    vis.clear();
}



return 0;
}
