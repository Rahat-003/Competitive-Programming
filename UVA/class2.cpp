#include <iostream>
#include <list>
using namespace std;
class Graph{
int V;
list<int>*adj;
public:
    Graph(int V);

    void fun(int x,int y);
    void print();
};
Graph::Graph(int V){
this->V=V;
adj=new list<int>[V+1];
}
void Graph::fun(int x,int y){
adj[x].push_back(y);
adj[y].push_back(x);
}
void Graph::print(){

for(int i=0;i<V;i++){
        cout<<i<<"->";
    for(auto it=adj[i].begin();it!=adj[i].end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

}
int main(){

    int n;
cin>>n;
Graph g(n);
int e;
cin>>e;


while(e--){
        int a,b;
        cin>>a>>b;
        g.fun(a,b);
}
g.print();

return 0;
}
