#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ar[]={2,3,5,7,13,17,19,31};

int main(){
  // freopen("10490.txt","r",stdin);
    int n;
    while(cin>>n){
        if(n==0) break;

        if(n==11 || n==23 || n==29 )
            printf("Given number is prime. But, NO perfect number is available.\n");
       else if((n%2==0 || n%3==0 || n==25) && n!=2 && n!=3)
            printf("Given number is NOT prime! NO perfect number is available.\n");


            for(int i=0;i<8;i++){
            if(n==ar[i]){
                ll x= (pow(2,n-1))*(pow(2,n)-1);
            printf("Perfect: %lld!\n",x );

            }
        }


    }



return 0;

}
