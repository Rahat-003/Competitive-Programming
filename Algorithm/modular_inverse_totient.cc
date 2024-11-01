#define mx (int)1e6+3
#include <bits/stdc++.h>
//#include <memory.h>
#include <stdio.h>
using namespace std;
int phi[mx];

void totient(){
    iota(phi,phi+mx,0);

    for(int i = 2; i<mx; i+=2)
        phi[i]/=2;

    for(int i = 3; i<mx; i++){
        if(phi[i]==i){
            --phi[i];
            for(int j = 2*i; j<mx; j+=i)
                phi[j]-=phi[j]/i;
        }
    }

}

int bal(int n,int p,int m){
    if(p==0)    return 1;
    if(p==1)    return n%m;

    if(p%2==0){
        int x = bal(n,p/2,m);
        return (x*x)%m;
    }
    else{
        int y = bal(n,p-1,m);
        return (y* (n%m))%m;
    }
}


int main(){
totient();
puts("Modular Inverse with totient(not efficient)...\n");

int n,m;
while(2==scanf("%d %d",&n,&m)){

        if(__gcd(n,m)!=1){
            puts("impossible");
            continue;
        }

    int ans = bal(n,phi[m]-1,m);
    printf("%d\n",ans);
}





   return 0;
}
