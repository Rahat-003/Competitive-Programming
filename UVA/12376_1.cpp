#include <bits/stdc++.h>
using namespace std;
int n,inc=0;
vector<int>val;
vector<vector<int> > v;
vector<bool>vis(n,false);
vector<int>total;

void dfs2(int c,int d){
    for(int i=0;i<v[c].size();i++){
        int child=v[c][i];
        total[child]=total[c]+val[child];
        dfs2(child,total[c]);
    }
}

void dfs(int m){
    vis[m]=true;
    for(int i=0;i<v[m].size();i++){
        int child = v[m][i];
        total[child] = val[child]+ total[m];
        if(!vis[child])
            dfs(child);
       else{
        int q=val[m];
        dfs2(child,q);
        }
    }
}

int main(){
//freopen("12376.txt","r",stdin);
int t,tc=1;
cin>>t;
while(t--){
    int e;
    cin>>n>>e;
    v.assign(n,vector<int>());
    total.assign(n,0);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        val.push_back(a);
    }
    for(int i=0;i<e;i++){
        int b,c;    cin>>b>>c;
        v[b].push_back(c);
    }
    dfs(0); int gt=-1,ind;
    for(int i=1;i<total.size();i++){
    if(total[i]>gt){
        gt=total[i];    ind=i;
    }
    }
    printf("Case %d: %d %d\n",tc++,gt,ind);
    val.clear();  vis.clear();  total.clear();
    v.clear();
}
return 0;
}
