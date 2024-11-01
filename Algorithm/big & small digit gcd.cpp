#include <iostream>
#include <algorithm>
using namespace std;


int main(){
int a;
string b;
cin>>a>>b;
int x=b.size();
int mod=0;
for(int i=0;i<x;i++){
    int c=b[i]-'0';
    mod=(10*mod+c)%a;
}
cout<<__gcd(mod,a);


return 0;
}
