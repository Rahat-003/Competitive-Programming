
#include <cstdio>
#include <cmath>
//using namespace std;

int factor(int n){
    int rt = sqrt(n);
    int tot = 0;
    if(rt*rt==n)    tot-=1;

    for(int i = 1; i*i<=n; i++){
        if(n%i==0)
            tot+=2;
    }
return tot;
}


int main(){
int t;

scanf("%d",&t);

while(t--){
    int a,b;
    scanf("%d %d",&a,&b);

    int mx,div = 0;

    for(int i = a; i<=b; i++){
    int cnt = factor(i);
    if(cnt>div){
      mx = i;
      div = cnt;
    }

    }

    printf("Between %d and %d, %d has a maximum of %d divisors.\n",a,b,mx,div);
}



return 0;
}
