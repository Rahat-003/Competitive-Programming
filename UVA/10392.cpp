#include <iostream>
using namespace std;
typedef long long ll
void prime(long long a){
    for(ll i=2;i*i<=a;i++){
        while(a%i==0){
            cout<<i<<endl;
        }
    }

}
int main(){
ll a;
while(cin>>a){
    cout<<prime(ll a);
}

return 0;
}
