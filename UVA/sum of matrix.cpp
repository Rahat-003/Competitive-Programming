#include <iostream>
using namespace std;
int main(){
int a[100][100];
int b[100][100];
int c[100][100];
int c1,r1,c2,r2;
cin>>r1>>c1;
for(int i=0;i<r1;i++){
    for(int j=0;j<c1;j++){
        cin>>a[i][j];
    }
}
for(int i=0;i<r1;i++){
    for(int j=0;j<c1;j++){
        cin>>b[i][j];
    }
}
for(int i=0;i<r1;i++){
    for(int j=0;j<c1;j++){
        c[i][j]=a[i][j]+b[i][j];
    }
}
for(int i=0;i<r1;i++){
    for(int j=0;j<c1;j++){
        cout<<c[i]+[j]<<" ";
    }
    cout<<endl;
}


return 0;
}


