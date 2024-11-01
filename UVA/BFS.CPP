#include <bits/stdc++.h>
using namespace std;
map<int,vector<int> >Graph;
void add_edge(int u,int v){
Graph[u].push_back(v);
Graph[v].push_back(u);
}
void print(){

for(auto it=Graph.begin();it!=Graph.end();++it){
    cout<<it->first<<"->";
    for(auto i=it->second.begin();i!=it->second.end();++i){
        cout<<*i<<" ";
    }
    cout<<endl;
}
}
void bfs(int s){
queue<int>q;
map<int,int>lev;
map<int,bool>vis;
vis[s]=true;
lev[s]=0;
q.push(s);
while(!q.empty()){

    int u=q.front();
    q.pop();
    for(auto it=Graph[u].begin();it!=Graph[u].end();++it){
    //    cout<<*it<<" ";
        if(vis[*it]==false){
            vis[*it]=true;
            lev[*it]=lev[u]+1;
            q.push(*it);
        }
    }
    cout<<endl;
}
for(auto it=lev.begin();it!=lev.end();++it){
    cout<<it->first<<" "<<it->second<<endl;
}

}
int main(){

int n;

cin>>n;
int e;
cin>>e;
for(int i=0;i<e;i++){
    int u,v;
    cin>>u>>v;
    add_edge(u,v);
}
print();
cout<<endl;
int s;
cin>>s;
bfs(s);
return 0;
}
