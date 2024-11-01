#include <bits/stdc++.h>
#include <cmath>
using namespace std;

void bb (int x,int y){

    int a,b,p;
    for(int i=1;i<=x;++i){
        p=10;
        a= y%p + y/p;
        y=a;
    }
    cout<<a<<endl;
}
int main(){

string s;

while(cin>>s && s!="0"){
    int y , x=s.length();
    y = atoi(s.c_str());
    if(y<10){
        cout<<y<<endl;
    }
     else bb(x,y);
}

return 0;
}
