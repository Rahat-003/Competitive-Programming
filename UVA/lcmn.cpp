#include <iostream>
#define ll long long
using namespace std;

ll gcd(ll a,ll b){
if(a%b==0)
    return b;
else
    return gcd(b%a,a);
}

int main(){

ll a,b;

cin>>a>>b;
ll m=1;/*
for(int i=a;i<=b;i++){
    m=(m*i)/gcd(m,i);
    cout<<m<<" ";
}*/
cout<<gcd(a,b)<<" "<<m<<endl;

return 0;
}
