#include <iostream>
#include <algorithm>
using namespace std;
int main(){
int a,b,c;
cin>>a>>b>>c;
cout<<a<<"x + "<<b<<"y = "<<c<<endl;
int d=__gcd(a,b);
if(c%d==0){
    cout<<"possible\n";
}
else cout<<"impossible\n";
return 0;
}
