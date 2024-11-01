#include <cstdio>
#include <iostream>
using namespace std;
bool check_prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
void Golden(int n){
int cnt=0;
for(int i=2;i<=n/2;i++){
    if(check_prime(i)&&check_prime(n-i)){
        //printf("%d = %d + %d\n",n,i,n-i);
          cnt++;
    }
}
cout<<cnt<<endl;
}
int main(){

int n;
while(cin>>n&&n){
    Golden(n);
}

return 0;
}
