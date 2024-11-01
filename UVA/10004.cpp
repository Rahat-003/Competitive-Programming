/// Bipartite graph check

#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> >v;
bool check(){
queue<int>q;
q.push(0);

vector<bool> clr(n,false);
clr[0]=true;
while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i=0;i<v[u].size();i++){
        int child = v[u][i];
        if(!clr[child]){
            clr[child]=!clr[u];
            q.push(child);
        }
        else if(clr[child]==clr[u])
            return false;
    }
}

return true;
}

int main(){

while(cin>>n){
        v.assign(n,vector<int>());
        if(n==0) break;
//    vector<vector<int> >v;
    int e;
    cin>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(!check())
        printf("NOT BICOLORABLE.\n");
    else printf("BICOLORABLE.\n");
    v.clear();
}


return 0;
}
