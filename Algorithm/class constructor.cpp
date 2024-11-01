#include <bits/stdc++.h>
using namespace std;

class biri{
    int a,b;
public:
    biri(int, int);
    int add(){
    return a+b;
    }
    int sub(){
    return a-b;
    }

};
biri::biri(int x,int y){
    a=x;
    b=y;
}


int main(){
int m,n;

while(cin>>m>>n){
    biri derby(m,n);
    cout<<derby.add()<<endl;
    cout<<derby.sub()<<endl;
    biri bal(n,m);
    cout<<bal.sub()<<endl;
}



return 0;
}
