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
//    int a,b;
        int a,b;
    while(cin>>a>>b){
        if(!a && !b)  break;
//        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(!check())
        printf("NO\n");
    else printf("YES\n");

    for(int i=0;i<v.size();i++)
      v[i].clear();
}


return 0;
}

