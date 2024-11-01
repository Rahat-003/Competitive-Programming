#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main(){
int a;
int tc=1;
while(cin>>a){
    if(a==0)    break;
    int b;
    int ar[a],i1=0;
    int total=0;
    while(a--){
        cin>>b;
        ar[i1]=b;
        total+=b;
        i1++;
    }
    int avg=total/i1;
    int sum=0;
    for(int i=0;i<i1;i++){
        sum+= abs(ar[i]-avg);
    }

    printf("Set #%d\nThe minimum number of moves is %d.\n\n",tc++,sum/2);

}

return 0;
}
