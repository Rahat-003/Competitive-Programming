#include <iostream>
#include <cstdio>
using namespace std;
int main(){
long long a,b;
int t;
cin>>t;
while(t--){
    cin>>a>>b;
    if(b%a==0){
        printf("%lld %lld\n",a,b);
    }
    else printf("-1\n");
}

return 0;
}
