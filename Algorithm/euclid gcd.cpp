#include <iostream>
using namespace std;

int bal(int a,int b){
    if(a==0) return b;

    else return bal(b%a,a);

}


int main(){
int a,b;
cin>>a>>b;
cout<<bal(a,b);


return 0;
}
