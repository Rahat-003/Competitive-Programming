#include <bits/stdc++.h>
using namespace std;

int ar[5][5][5];

int main(){
    int c=1;
memset(ar,-1,sizeof ar);
for(int i=0;i<5;i++)
    for(int j=0;j<5;j++)
    for(int k=0;k<5;k++)
    cout<<c++<<" "<<ar[i][j][k]<<endl;



return 0;
}
