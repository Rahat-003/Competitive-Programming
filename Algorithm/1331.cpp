#include <iostream>

#include <iomanip>

#include <cmath>

#define pi acos(-1)

using namespace std;

int main(){

int t;
cin>>t;
int k=0;
while(t--){
    double r1,r2,r3;
    cin>>r1>>r2>>r3;
    double a=r2+r3;
    double b=r1+r3;
    double c=r1+r2;
    double A=acos(((b*b)+(c*c)-(a*a))/(2*b*c));
    double B=acos(((a*a)+(c*c)-(b*b))/(2*a*c));
    double C=acos(((a*a)+(b*b)-(c*c))/(2*a*b));
    double s=(a+b+c)/2.0;
    double area=sqrt(s*(s-a)*(s-b)*(s-c));
    double fin=area-((.5*r1*r1*A)+(.5*r2*r2*B)+(.5*r3*r3*C));
    cout<<fixed<<setprecision(10)<<"Case "<<++k<<": "<<fin<<endl;

}

return 0;
}
