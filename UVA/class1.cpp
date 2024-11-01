#include <iostream>
#include <list>
using namespace std;
list <int>l[100];
void add(int u,int v){
l[u].push_back(v);
l[v].push_back(u);
}
int main(){
int n;
cin>>n;
int e;
cin>>e;
for(int i=0;i<e;i++){
    int a,b;
    cin>>a>>b;
    add(a,b);
}
for(int i=0;i<n;i++){
        cout<<i<<"->";
        for(auto it=l[i].begin();it!=l[i].end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

return 0;
}
