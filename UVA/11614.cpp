#include <iostream>
#include <cmath>
using namespace std;
int main (){
int t;
cin>>t;
long long sum,m,n;
while(t--){
    cin>>sum;
    cout<<(int)((-1+sqrt(1+8*sum))/2)<<endl;
}


return 0;
}
