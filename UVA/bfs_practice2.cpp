#include <bits/stdc++.h>
using namespace std;
map<int,vector<int>> tree;
void edge(int a,int b){
tree[a].push_back(b);
tree[b].push_back(a);
}
void bfs(int root){
queue<int>q;
map<int,bool>visit;
map<int,int>lvl;
lvl[root]=0;
visit[root]=true;
q.push(root);
while(!q.empty()){
    int u=q.front();
    q.pop();
    for(auto it=tree[u].begin();it!=tree[u].end();++it){
        if(visit[*it]==false){
            visit[*it]=true;
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
    int a,b;
    cin>>a>>b;
    edge(a,b);
}
for(auto i=tree.begin();i!=tree.end();++i){
    cout<<i->first<<"->"<<" ";
    for(auto it=i->second.begin();it!=i->second.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int root;
cin>>root;
bfs(root);

return 0;
}
