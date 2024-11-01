#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
int a,b,s,x,d,y;
while (cin>>a>>b){
        s=a;
        d=b;
    while(s%d!=0){
        x=s%d;s=d;
        d=x;
    }



    cout<<a/d<<"/"<<b/d<<endl;
}


return 0;
}
