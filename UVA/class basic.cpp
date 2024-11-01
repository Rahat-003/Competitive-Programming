#include <iostream>
using namespace std;
class ball{
//int x,y;
public:
    //ball(int x,int y);
    int bal(int x,int y);
};
int ball::bal(int a,int b){
return a*b;
}
int main(){
ball a;
int m,n,t;

while(cin>>m>>n){

   cout<<a.bal(m,n)<<endl;
}
return 0;
}
