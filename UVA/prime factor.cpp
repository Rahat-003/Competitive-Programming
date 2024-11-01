#include <iostream>
using namespace std;
int main(){
int a;
while(cin>>a){
//    cout<<a<<" "<<"="<<" ";
        if(a<0){
            cout<<-1<<" ";
            a=-a;
        }
while(a%2==0){
   cout<<2<<" ";
    a/=2;
}

for(int i=3;i*i<=a;i+=2){
    while(a%i==0){
        cout<<i<<" ";
        a/=i;
    }
}
if(a>2){
    cout<<a;
}
cout<<endl;
}
return 0;
}
