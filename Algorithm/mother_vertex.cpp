#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<bool> vis;
int n,e;

void dfs(int a){
    vis[a] = true;
    for(auto child:v[a]){
        if(!vis[child])
            dfs(child);
    }
}

int check(){
    int v = 0;
    for(int i = 0 ; i<n; i++){
        if(!vis[i]){
            dfs(i);
            v = i;
        }
    }
    vis.assign(n,false);
    dfs(v);
    for(int i = 0 ; i<vis.size(); i++)
        if(!vis[i]) return 0;
    return v;
}


int main(){

scanf("%d %d",&n,&e);
v.assign(n,vector<int>());
vis.assign(n,false);
while(e--){
    int a,b;
    scanf("%d %d",&a,&b);
    v[a].push_back(b);
}

int x = check();

x? printf("%d\n",x): printf("No mother \n");




return 0;
}
