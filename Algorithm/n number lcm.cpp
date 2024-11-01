#include <iostream>
#include <algorithm>

using namespace std;
int lcm(int a,int b){
return (a*b)/__gcd(a,b);
}

int main(){

int a;
cin>>a;int ar[a];
for(int i=0;i<a;i++){
    cin>>ar[i];
}
int ans=1;
for(int i=0;i<a;i++){
    ans=lcm(ans,ar[i]);
}
cout<<ans;
return 0;
}
