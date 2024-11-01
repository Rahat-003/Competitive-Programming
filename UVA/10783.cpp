#include <iostream>
#include <cstdio>
using namespace std;
int main(){
int t,a,b,c=0;
cin>>t;
while(t--){
        int sum=0;
    cin>>a>>b;

    for(int i=a;i<=b;i++){
        if(i%2!=0){
        sum+=i;
        }
    }

    printf("Case %d: %d\n",++c,sum);
}


return 0;
}
