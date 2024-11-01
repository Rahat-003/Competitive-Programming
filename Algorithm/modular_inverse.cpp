
#include <cstdio>

int gcd(int a,int b,int &x,int &y){
    if(a==0){
        x = 0;
        y = 1;
        return b;
    }
    int x1,y1,g = gcd(b%a,a,x1,y1);
    y = x1;
    x = (g-b*y)/a;
    return g;
}


int main(){
int n,m;

puts("Modular Inverse with Extended Euclid...\n");

while(2==scanf("%d %d",&n,&m)){
        int x,y,g = gcd(n,m,x,y);
        if(g!=1){
            puts("impossible");
            continue;
        }
        int ans = (x%m + m)%m;
        printf("%d\n",ans);
}



return 0;
}
