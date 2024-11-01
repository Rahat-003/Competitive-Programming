#include <bits/stdc++.h>
using namespace std;
map<int,vector<int> >graph;
void add(int u,int v){
graph[u].push_back(v);
graph[v].push_back(u);
}
int main(){
int a,b;
list<int>l;
while(cin>>a>>b&&a&&b){
    add(a,b);}
    for(auto it=graph.begin();it!=graph.end();++it){
        cout<<it->first<<"->";
        for(auto i=it->second.begin();i!=it->second.end();++i){
            cout<<*i<<" ";
        }
        cout<<endl;
    }


return 0;
}
