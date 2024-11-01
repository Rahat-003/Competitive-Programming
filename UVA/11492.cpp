#include <iostream>
using namespace std;
int main(){
int n,a,x,y;
cout<<"Lumberjacks:\n";
cin>>n;
int b[10];

for(int i=0;i<n;i++){
         x=y=0;
    for(int j=0;j<10;j++){
        cin>>a;
        b[j]=a;
        }
    for(int k=1; k<10;k++){
        if(b[0]<b[9]){
            x++;
            if(b[k-1]>b[k]){
                    cout<<"Unordered\n";
                break;
            }
        }
        else if(b[0]>b[9]){
            y++;
            if(b[k-1] < b[k]){
                cout<<"Unordered\n";
                break;
            }
        }
        if(x==9){
            cout<<"Ordered\n";
        }
        if(y==9){
            cout<<"Ordered\n";
        }
        }
}
return 0;
}
