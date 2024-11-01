#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> > v(n);
vector<bool>vis(n,false);
void dfs(int a){
    vis[a]=true;
    cout<<a<<" ";
    for(int i=0;i<v.size();i++){
        int child = v[a][i]
    }




}

int main(){

int e;
cin>>n>>e;
while(e--){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
}
dfs();
return 0;
}
