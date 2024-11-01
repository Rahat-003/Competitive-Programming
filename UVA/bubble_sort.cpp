#include <iostream>
using namespace std;


int main(){

int n;
while(cin>>n){
    int a[n],b;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
            int x=a[j];
            a[j]=a[j+1];
            a[j+1]=x;
            }

        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    cout<<endl;


}



return 0;
}
