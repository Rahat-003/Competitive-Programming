#include <iostream>
#include <cmath>
#define pi acos(-1)
#include <iomanip>
using namespace std;

int main(){
int t;
cin>>t;
int k=0;
while(t--){
    double r,n;
    cin>>r>>n;
    double ans=r*((sin(pi/n))/(1+sin(pi/n)));
    cout<<"Case "<<++k<<": ";
    if(((ans*1.0)/(int)ans)==1)
        cout<<fixed<<setprecision(0)<<ans<<endl;
    else
        cout<<fixed<<setprecision(10)<<ans<<endl;

}

return 0;
}
