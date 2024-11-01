#include <iostream>
using namespace std;

void swp(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;

}
void swp(int a,int b){
    int t=a;
    a=b;
    b=t;
}

int main(){
int a[]={1,2,3,4,5};
swp(&a[3],&a[4]);
cout<<a[3]<<" "<<a[4]<<" ";

return 0;
}
