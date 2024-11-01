#include <iostream>
using namespace std;

int main(){
int a[100];
int n;
cin>>n;
int b;
for(int i=0;i<n;i++){
    cin>>a[i];
}
cin>>b;
int c,d;
for(int i=0;i<n;i++){
    if(a[i]==b){
cout<<i;
break;
    }
   // else {d=i;}
}




return 0;
}
