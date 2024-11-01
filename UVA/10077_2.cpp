#include <iostream>
using namespace std;
int main(){
int A,B;
while(cin>>A>>B){
    if(A==1 && B==1)break;
    int a=0,b=1,c=1,d=0,e=1,f=1;
    while(1){
        if(e==A && f==B)break;
        if(e*B>f*A){
            cout<<"L";
            c=e;d=f;
        }
        else{
            cout<<"R";
            a=e;b=f;
        }
        e=a+c;f=b+d;

    }
 cout<<endl;
}


return 0;
}
