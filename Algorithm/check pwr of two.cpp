#include <iostream>
using namespace std;
bool check(int n){

return (n&&(n&(n-3)));
}

int main(){
    int n;
while(cin>>n){
    for(int i=2;i<=n;i++){
    if(!check(i))
        cout<<i<<" ";
    }
    cout<<endl;
}



return 0;
}
