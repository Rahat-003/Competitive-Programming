#include <iostream>
#include <utility>
#define pp pair<int,int>
#include <list>
using namespace std;
int V;
list<pp>adj[100];
void add_edge(int a,int b,int c){
adj[a].push_back(make_pair(b,c));
adj[b].push_back(make_pair(a,c));
}
int main(){

 cin>>V;
 int e;
 cin>>e;
 while(e--){

    int a,b,c;
    cin>>a>>b>>c;
    add_edge(a,b,c);
 }
for(int i=0;i<V;i++){
    cout<<i<<"->";
    for(auto it=adj[i].begin();it!=adj[i].end();++it){
        cout<<it->first<<"="<<it->second<<";";
    }
    cout<<endl;
}
return 0;
}

