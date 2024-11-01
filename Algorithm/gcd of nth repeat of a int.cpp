#include <iostream>
#include <algorithm>
using namespace std;

int main(){
int n;
cin>>n;
int r,s;
cin>>r>>s;
for(int i=0;i<r;i++){
    cout<<n;
}
cout<<" ";
for(int i=0;i<s;i++){
    cout<<n;
}
cout<<endl;
for(int i=0;i<__gcd(r,s);i++){
    cout<<n;
}
cout<<endl;

return 0;
}
