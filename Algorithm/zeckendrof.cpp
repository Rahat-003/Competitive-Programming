#include <iostream>
using namespace std;

int fibsum(int a){
    if(a==0 || a==1)
        return a;
    int f1=0,f2=1,f3;
    while(f2<=a){
        f3=f1+f2;
        f1=f2;
        f2=f3;
    }
    return f1;

}


void prnt(int a){
    while(a>0){
        int fb=fibsum(a);
        cout<<fb<<" ";
        a=a-fb;
    }
cout<<endl;

}


int main(){
int a;
while(cin>>a)
    prnt(a);

return 0;

}
