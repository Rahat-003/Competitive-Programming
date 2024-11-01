#include <cstdio>

using namespace std;

#define mx 10000000
bool ar[mx+4];

void sieve(){
    ar[0] = ar[1] = true;
    for(int i = 4;i<mx; i+=2)
        ar[i] = 1;
    for(int i = 3;i*i<=mx;i+=2){
        if(!ar[i]){
            for(int j = i*i; j<mx; j+=2*i)
                ar[j] = 1;
        }
    }

}

void bal(int &a,int &b,int n){

    for(int i = 0; i<n;i++){
        if(!ar[i] && !ar[n-i]){
            a = i;
            b = n-i;
            return;
        }
    }

}



int main(){

sieve();
int n;

while(scanf("%d",&n)==1){
    if(n<8){
    puts("Impossible.");
    continue;
    }

    int a,b,c,d;
        a = 2;
    if(n&1)
        b = 3;
    else b = 2;

    bal(c,d,n-a-b);

    printf("%d %d %d %d\n",a,b,c,d);

}


return 0;
}
