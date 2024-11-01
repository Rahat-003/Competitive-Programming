#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > v;
void pl(int n){
cout<<"+";
for(int i=0;i<2*n-1;i++)
    cout<<"-";
cout<<"+\n";
}
void dfs(int n, vector<bool> &vis, const int &t){
vis[n] = false;
for(int i=0; i<v[n].size();i++){
    int child = v[n][i];
    if(child!=t && vis[child])
        dfs(child, vis, t);
}
}


int main(){ freopen("11902.txt","r",stdin);
int t,tc=1;
cin>>t;
while(t--){
    vector<bool>vis;
    vector<vector<bool> >visited;
    int n;  cin>>n;
    vis.assign(n,true);
    visited.assign(n,vector<bool>(n,true));
    v.assign(n,vector<int>());
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        int a;  cin>>a;
        if(a) v[i].push_back(j);
    }
    dfs(0,vis,-1);
    for(int i=1;i<n;i++)
        dfs(0,visited[i],i);
printf("Case %d:\n",tc++);
    for(int i=0;i<n;i++){
    pl(n); cout<<"|";
    for(int j=0;j<n;j++){
    if(!vis[j] && visited[i][j])
        cout<<"Y|";
    else cout<<"N|";
    }
    cout<<endl;
    }
    pl(n);
}
return 0;
}
