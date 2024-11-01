#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b,int &x,int &y){
    if(a==0){
        y = 1;
        x = 0;
        return b;
    }
    int x1,y1;

    int g = gcd(b%a,a,x1,y1);

    y = x1;
    x = (g-b*y)/a;

    return g;

}

int main(){

int a,b;

while(cin>>a>>b){

    int x,y;

    cout<<gcd(a,b,x,y)<<endl;;   /// any function (void/bool/int) can be called inside main function..

    cout<<x<<" "<<y<<endl;


}

return 0;
}


