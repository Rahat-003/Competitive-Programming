#include <iostream>
using namespace std;

int main(){

int n,r;
while(cin>>n>>r){
        int x,y;x=y=1;
    for(int i=n;i>n-r;i--){
        x*=i;
    }
    for(int i=2;i<=r;i++){
        y*=i;
    }
    cout<<x/y<<endl;

}


return 0;
}
