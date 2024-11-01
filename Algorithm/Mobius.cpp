#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <memory.h>
#include <algorithm>
#define case        printf("Case %d: ",++tc);
#define read        freopen("tst.txt","r",stdin)
#define write       freopen("out.txt","w",stdout)
typedef long long ll;
using namespace std;
#define pi acos(-1)
#define mx 100003

bool ar[mx];
int mu[mx];

void sieve(){
    for(int i = 1; i<mx; i++){
        mu[i] = 1;
    }

    for(int i = 2; i*i<=mx; i++){
        if(!ar[i]){
            mu[i] = -1;
            for(int j = 2; i*j<mx; j++){
                ar[i*j] = true;
                if(j%i==0)  mu[i*j] = 0;
                else    mu[i*j]*=-1;
            }
        }
    }
}


int main(){
int t,tc = 0;
sieve();

for(int i = 0; i<100; i++)
    printf("%2d %2d\n",i,mu[i]);



return 0;
}
