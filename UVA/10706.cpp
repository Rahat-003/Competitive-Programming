#include <iostream>
#include <cstdio>
using namespace std;


int main(){
   // freopen("10706.txt","r",stdin);
int t;
cin>>t;
while(t--){
    int a;
    cin>>a;
    if(a>80){
        a=a%80;
    }
    string s="11212312341234512345612345671234567812345678912345678910123456789101112345678910";
    cout<<s[a-1]<<endl;
    cout<<a<<endl;
}

return 0;
}
