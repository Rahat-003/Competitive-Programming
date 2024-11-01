#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> mp;
void add_edge(int u,int v){
mp[u].push_back(v);
mp[v].push_back(u);
}
void bfs(int s){
map<int,bool>vis;
map<int,int>lvl;
queue<int>q;
vis[s]=true;
lvl[s]=0;
q.push(s);
while(!q.empty()){
    int u;
    u=q.front();
    q.pop();
    for(auto it=mp[u].begin();it!=mp[u].end();++it){
        if(vis[*it]==false){
            vis[*it]=true;
            lvl[*it]=lvl[u]+1;
            q.push(*it);
        }
    }

}
for(auto i=lvl.begin();i!=lvl.end();++i){
    cout<<i->first<<" "<<i->second<<endl;
}

}




int main(){
int e;
cin>>e;
while(e--){
    int u,v;
    cin>>u>>v;
    add_edge(u,v);
}
int s;
cin>>s;
bfs(s);


return 0;
}
