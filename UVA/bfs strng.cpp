#include <bits/stdc++.h>
using namespace std;
map<string, vector<string>> mp;
void add_edge(string u,string v){
mp[u].push_back(v);
mp[v].push_back(u);
}
void bfs(string s){
map<string,bool>vis;
map<string,int>lvl;
queue<string>q;
vis[s]=true;
lvl[s]=0;
q.push(s);
while(!q.empty()){
    string u;
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
    string u,v;
    cin>>u>>v;
    add_edge(u,v);
}
string s;
cin>>s;
bfs(s);


return 0;
}
