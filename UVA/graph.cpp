#include <iostream>
#include <map>
#include <vector>
#include <list>
using namespace std;
map<int,vector<int> >graph;
void add(int u,int v){
graph[u].push_back(v);
graph[v].push_back(u);

}
int main(){
list<int>l;
int a,b;
while(cin>>a>>b&&a&&b){
    add(a,b);
}
for(auto it=graph.begin();it!=graph.end();++it){
        cout<<it->first<<"->";
    for(auto i=it->second.begin();i!=it->second.end();++i){
        cout<<*i<<" ";
    }
    cout<<endl;
}
return 0;
}
