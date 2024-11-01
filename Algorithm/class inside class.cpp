#include <bits/stdc++.h>
using namespace std;

class fun1{
    double radius;
public:
    fun1(double r) : radius(r){}
    double area (){
    return acos(-1)*radius*radius;
    }
};

class fun2{
    double height;
    fun1 result;
public:
    fun2(double r, double h) : result(r), height(h) {}
    double vol(){
    return result.area()*height;
    }
};


int main(){
double a,b;
while(cin>>a>>b){
    fun2 volume (a,b);
    cout<<volume.vol()<<endl;

}



return 0;
}
