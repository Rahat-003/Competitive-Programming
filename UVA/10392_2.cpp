#include <iostream>
using namespace std;
void prime(long long a){
    for(long long i=2;i*i<=a;i++){
        while(a%i==0){
            cout<<" "<<" "<<" "<<" "<<i<<endl;
            a/=i;
        }
    }
    if(a!=1)
cout<<" "<<" "<<" "<<" "<<a<<endl;
}
int main(){
long long a;
while(cin>>a&&a>0){
    prime(a);
    cout<<endl;

}

return 0;
}

