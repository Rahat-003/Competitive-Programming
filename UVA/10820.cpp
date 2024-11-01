
#include <cstdio>
#define mx (int)50e3+3

int phi[mx],ans[mx];

void totient(){
    for(int i = 0; i<mx; i++)
        phi[i] = i;

    for(int i = 2; i<mx; i+=2)
        phi[i]/=2;

    for(int i = 3; i<mx; i+=2){
        if(phi[i]==i){
            --phi[i];
            for(int j = i+i; j<mx; j+=i){
                phi[j]-=phi[j]/i;
            }
        }
    }
}

void calc(){
    ans[1] = 1;
    for(int i = 2; i<mx; i++){
        ans[i] = ans[i-1]+2*phi[i];
    }
}

int main(){

totient();
calc();
int n;

while(1==scanf("%d",&n)){
    if(!n)  break;
    printf("%d\n",ans[n]);
}



return 0;
}
