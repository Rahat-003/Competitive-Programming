#include <iostream>
using namespace std;
int main(){
int a,b;
int p[100];
while(cin>>a){
    for(int i=0;i<a;i++){
        cin>>b;
        p[i]=b;
    }
    for(int i=0; i<a-1;i++){
        for(int j=0; j<a-1-i; j++){
            if(p[j+1]<p[j]){
                int x=p[j];
                p[j]=p[j+1];
                p[j+1]=x;
            }
        }
    }
    for(int i=0; i<a; i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
}


return 0;
}
