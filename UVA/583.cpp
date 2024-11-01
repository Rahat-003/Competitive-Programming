#include <iostream>
using namespace std;
#define ll long long
void prime(ll n){

    for(ll i=2;i*i<=n;i++){
        while(n%i==0&&n!=i){
            cout<<i<<" "<<"x"<<" ";
            n/=i;
        }
    }
    cout<<n<<endl;

}
int main(){
//    freopen("583.txt","r",stdin);
ll n;
while(cin>>n&&n){
    if(n<0){
        cout<<n<<" "<<"="<<" ";
        n*=-1;
        cout<<-1<<" "<<"x"<<" ";
        prime(n);
    }
   else  {
        cout<<n<<" "<<"="<<" ";
        prime(n);
   }
}

return 0;
}
