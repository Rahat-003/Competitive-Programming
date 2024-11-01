#include <bits/stdc++.h>
using namespace std;
int n,total,node;
vector<vector<int> > v;
vector<bool>vis;
vector<int>val;

void dfs(int a){
vis[a]=true;
int temp=0;
for(int i=0;i<v[a].size();i++){
    int child = v[a][i];
    if(val[child]>temp){
        temp=val[child];
        node=child;
    }
}
total+=val[node];
if(!vis[node] && v[node].size()!=0)
    dfs(node);
}

int main(){
   // freopen("12376.txt","r",stdin);
int t,tc=1;
cin>>t;
while(t--){
        total=0;
    int e;
    cin>>n>>e;
    for(int i=0;i<n;i++){
        int a;
        cin>>a; val.push_back(a);
    }
    v.assign(n,vector<int>());
    vis.assign(n,false);
    for(int i=0;i<e;i++){
        int c,d;
        cin>>c>>d;
        v[c].push_back(d);
    }
    dfs(0);
   printf("Case %d: %d %d\n",tc++,total,node);
    vis.clear();
    val.clear();
    for(int i=0;i<n;i++)
    v[i].clear();

}
return 0;
}
