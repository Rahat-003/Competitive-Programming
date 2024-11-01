#include <iostream>
using namespace std;

#define mx 1000000

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
    if(!n)  break;
printf("%d:\n",n);

int x=-1,y=-1;

if(!(n&1)){

for(int i = n-1; i>= (n/2)-2; i-=2){
    if(i==1)   i=2;
    if( n-i>=0 && !ar[i] && !ar[n-i] ){
        x = i;
        y = n-i;
        break;
    }

}
}

else{
    if( n>3 && !ar[n-2]){
        x = 2;
        y = n-2;
    }
}

if(x>y) swap(x,y);

if( (x==-1 && y==-1) )  printf("NO WAY!\n");
else printf("%d+%d\n",x,y);

}

return 0;
}
