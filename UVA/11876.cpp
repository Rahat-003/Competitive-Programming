#include <iostream>
using namespace std;
/*
int funct(int a,int b){
    int c,d=0;
    for(int i=1;i<=b;i++){
        c=i;
        while(c<=)
    }


}
*/

int main(){
int t;
cin>>t;
while(t--){
    int a,b;cin>>a>>b;
    int cnt=0,c,i=1;
    while(i<=b){
            c=0;
        for(int j=1;j<=i;j++){
            if(i%j==0){
                c++;
                i+=c;
            }
        }
        if(i>=a){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
return 0;
}
