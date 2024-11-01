#include <bits/stdc++.h>
using namespace std;

class node{
int m;
list<int>*l;
public:
    node(int m);
    void fun(int x, int y);
    void print();
};
node::node(int m){

    this->m=m;
    l= new list <int>[m+1];
}
void node::fun(int x,int y){
    l[x].push_back(y);
    l[y].push_back(x);
}
void node::print(){
    for (int i=0; i<m; i++)
    {
        cout<<i<<"->";
        for (auto it=l[i].begin();it!=l[i].end();++it)
        {
            /* code */cout<<*it<<" ";
        }
        cout<<endl;
    }
}

int main(){

int n;
cin>>n;
node f(n);
int e;
cin>>e;

while(e--){
    int a,b;
    cin>>a>>b;
    f.fun(a, b);
}

    f.print();

return 0;
}
