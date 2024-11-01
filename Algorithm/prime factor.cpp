#include <iostream>
using namespace std;

#define int long long

main(){

int n;
while(cin>>n){

while(n%2==0){
    cout<<2<<" ";
    n/=2;
}
int b=n;

for(int i=3;i*i<=n;i+=2){
    while(b%i==0){
        cout<<i<<" ";
        b/=i;
    }
}

if(b>1)cout<<b;
cout<<endl;


}
return 0;
}
