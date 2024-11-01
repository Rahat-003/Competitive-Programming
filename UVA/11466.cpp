#include <iostream>
#define ll long long
using namespace std;
int main(){
ll n;
while(cin>>n&&n){
    ll result;
    ll sum=0;
    if(n<0){
        n*=-1;
    }
    for(int i=2;i*i<=n&&n!=1;i++){
        while(n%i==0){
            n/=i;
            int c=i;
            sum++;
        }

    }
    if(sum==1){
        c=-1;
    }

}


return 0;
}
