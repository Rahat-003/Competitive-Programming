/********
    No. of numbers having gcd g from 1 to N:
        if(N%g!=0)  return 0;
        else        return phi[N/g];
********/
#include <cstdio>
#include <iostream>
using namespace std;

#define MAX 5000001

int phi[MAX];

void sieve(){

  for(int i=1;i<MAX;i++)
    phi[i]=i;

    for(int i=2;i<MAX;i+=2)
    phi[i]>>=1;

    for(int i=3;i<MAX;i+=2)
      if(phi[i]==i){
        --phi[i];
        for(int j=i+i;j<MAX;j+=i)
          phi[j]-=phi[j]/i;
      }
}

int main() {
  sieve();
  for(int i=1;i<=100;i++)
    printf("%d %d\n",i,phi[i]);
int n;
cin>>n;
cout<<phi[n]<<endl;
  return 0;
}

