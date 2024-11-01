#include <bits/stdc++.h>
using namespace std;

class biri{
int a,b,c;
public:
    void pp(int ,int );
    int add(int a,int b)   {
    return a+b;
    }
    int sub(int a,int b){
    return a-b;
    }
};
void biri::pp(int x,int y){
    a=x;
    b=y;
}

int main(){
biri derby;
int m,n;
while(cin>>m>>n){
    derby.pp(m,n);
    cout<<"Summation is    "<<derby.add(m,n);
    cout<<"\nSubstraction is "<<derby.sub(m,n)<<endl;

}

return 0;
}



