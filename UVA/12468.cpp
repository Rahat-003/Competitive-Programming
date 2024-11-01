#include <iostream>
#include <cmath>
using namespace std;
int main(){
int a,b;
while(cin>>a>>b && a!=-1 && b!=-1)
{
    int c= abs(a-b);
    if(c>50){
        if(a>b){
            cout<<100+b-a<<endl;
        }
        else cout<<100+a-b<<endl;
    }
    else cout<<c<<endl;
}
return 0;
}

