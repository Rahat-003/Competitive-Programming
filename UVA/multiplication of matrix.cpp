#include <iostream>
using namespace std;
int main(){
int a[100][100];
int b[100][100];
int c[100][100];
int r1,c1,r2,c2;
cin>>r1>>c1;
cin>>r2>>c2;
for(int i=0;i<r1;i++){
    for (int j=0;j<c1;j++){
        cin>>a[i][j];
    }
}
for(int i=0;i<r2;i++){
    for (int j=0;j<c2;j++){
        cin>>b[i][j];
    }
}
if(c1==r2)

    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
                c[i][j]=0;
            for(int k=0;k<r2;k++){
                c[i][j]+=a[i][k]*b[k][j];
        }
    }
}

else{
    cout<<"impossible"<<endl;
}
for(int i=0;i<r1;i++){
    for(int j=0;j<c2;j++){
        cout<<c[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}
