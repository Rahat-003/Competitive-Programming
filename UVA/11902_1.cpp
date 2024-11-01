
#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> > v(105);

void pl(){
cout<<"+";
for(int i=1;i<2*n;i++)
    cout<<"-";
cout<<"+\n";
}
void dfs(int a, vector<bool> &bb, const int &c){
bb[a] = false;
for(int i=0;i<v[a].size();i++){
    int child = v[a][i];
    if(bb[child] && child!=c)
        dfs(child,bb,c);
}
}


int main(){// freopen("11902.txt","r",stdin);
int t,tc=1;
cin>>t;
while(t--){
cin>>n;
for(int i=0;i<105;i++)
    v[i].clear();

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        int a;
        cin>>a;
        if(a)
        v[i].push_back(j);
    }
}
vector<vector<bool> > vis(n);
vis.assign(n,vector<bool>(n,true));
vector <bool> visi(n,true);

dfs(0,visi,-1);
cout<<"Case "<<tc++<<":\n";
for(int i=1;i<n;i++)
    dfs(0,vis[i],i);

for(int i=0;i<n;i++){
    pl();
    cout<<"|";
    for(int j=0;j<n;j++){
    if(!visi[j] && vis[i][j])
        cout<<"Y|";

    else cout<<"N|";
    }
    cout<<endl;
}
pl();

}


return 0;
}
