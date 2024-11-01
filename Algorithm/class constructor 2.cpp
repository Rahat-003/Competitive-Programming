#include <bits/stdc++.h>
using namespace std;

class operation{
    double radius;
public:
    operation(double radius);
    double area(){
        double ar = acos(-1) * radius* radius;
        return ar;
    }
    double circum(){
    return 2*acos(-1)*radius;
    }

};
    operation::operation(double a){
        radius = a;
    }

int main(){
    double a;
    while(cin>>a){
operation bal = {a};
    cout<<"Area is "<<bal.area()<<endl;
    cout<<"circumference is "<<bal.circum()<<endl;
    }

return 0;
}
