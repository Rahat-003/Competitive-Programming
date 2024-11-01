#include <iostream>
using namespace std;
int nod(int x){
    int ret = 1;
    for(int i = 2;i*i<= x;++i){
        if(x % i == 0){
            int cont = 1;

            while(x % i == 0){
                x /= i;
                ++cont;
            }
            ret *= cont;
        }
    }
    if(x > 1) ret *= 2;
    return ret;
}
int main(){
    int n;
while(cin>>n){

cout<<nod(n)<<endl;
}
return 0;
}
