#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b,int &x,int &y){

if(!a){
    x=0, y=1;
    return b;
}

int x1,y1,g;
 g=gcd(b%a,a,x1,y1);

x=y1-(b/a)*x1;
y=x1;

return g;
}
/*
void modinv(int a,int b){
    int x,y;
int g=gcd(a,b,&x,&y);
if(g!=1)
    printf("doesn't exist\n");
else
//    printf("%d",(x+b)%b);
    printf("%d",(y+a)%a);

}
*/

int main(){

int a,b,x,y;
scanf("%d %d",&a,&b);
//modinv(a,b);
int g = gcd(a,b,x,y);

cout<<x<<" "<<y<<endl;



return 0;
}
