#include <bits/stdc++.h>
using namespace std;

int f(int a){
if(a==3)
    return 3;
return a*f(a-1);
}

int main(){

cout<<f(6);




return 0;
}
