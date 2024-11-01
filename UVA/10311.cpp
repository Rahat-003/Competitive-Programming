#include <iostream>
using namespace std;

#define mx 100000000

bool ar[mx+5];

void sieve(){
    ar[0] = ar[1] = 1;
    for(int i = 4; i<mx; i+=2)
        ar[i] = true;

    for(int i = 3; i*i<=mx+3; i+=2){
        if(!ar[i]){
            for(int j = i*i; j<mx; j+=2*i)
                ar[j] = true;
        }
    }

}


int main(){

sieve();

int n;

while(cin>>n){

int m = n/2;

int x=-1,y=-1;

if(!(n&1))
for(int i = m; i>=0; i--){

    if(!ar[i] && !ar[n-i] && i+i!=n){
        x = i;
        y = n-i;
        break;
    }

    if(m&1) i--;
}

else{
    if( n>3 && !ar[n-2]){
        x = 2;
        y = n-2;
    }
}

if(x>y) swap(x,y);

if( (x==-1 && y==-1) || x==y )  printf("%d is not the sum of two primes!\n",n);
else printf("%d is the sum of %d and %d.\n",n,x,y);

}

return 0;
}
