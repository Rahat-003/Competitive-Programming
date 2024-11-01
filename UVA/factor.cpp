#include <iostream>
using namespace std;
int main(){

int a;
while(cin>>a){

    int c=0,m;
    for(m=1;m*m<=a;m++){
    if(a%m==0){
      c+=2;  cout<<m<<" "<<a/m<<" ";
      if(m*m==a){c-=1;}
    }
    }
    cout<<endl<<c<<endl;
}



return 0;
}
