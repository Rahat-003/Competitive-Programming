#include <iostream>
#include <vector>
using namespace std;

vector<int> v(100,0);


int fib(int n){
if(n==0) return 0;
if(n==1) return 1;
if(v[n]) return v[n];
else {
    v[n]= fib(n-1) + fib(n-2);
    return v[n];
}
return -1;


}


int main(){

int a;
while(cin>>a){

cout<<fib(a);

}

return 0;
}
