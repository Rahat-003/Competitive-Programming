#include <iostream>
using namespace std;

int bal[100][100];

int ncr(int n,int r){
if(n==r || r==0)
    return 1;
if(r==1) return n;
if(bal[n][r])return bal[n][r];
else{
    int x=ncr(n-1,r)+ ncr(n-1,r-1);
    return x;
}



}


int main(){
int n;
while(cin>>n){
   // int bal[n][n];
    for(int i=0; i<=n;i++){
            cout<<i<<"-> ";
        for(int j=0;j<=i;j++){
           cout <<ncr(i,j)<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
}


return 0;
}
