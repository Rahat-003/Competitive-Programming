#include <iostream>
using namespace std;
double err(double n,double m){
if((m*m*m)>n)
    return (m*m*m)-n;
else
    return n-(m*m*m);
}
double sqt(double n){
double l=0;
double h=n;
double e=.000001;


while(true){

    double m=(h+l)/2;

    if(err(n,m)<=e)
        return m;
    if(m*m*m>n)
        h=m;
    else
        l=m;


    }

}
int main(){
double n;
cin>>n;
cout<<sqt(n)<<" ";
return 0;
}
