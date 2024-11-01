#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long

ll ar[51];
void fib(){
    ar[0]=1;
    ar[1]=2;
    ll a=1,b=2,c;
    for(int i=2;i<51;i++){
        c=a+b;
        a=b;
        b=c;
        ar[i]=b;
    }

}

int main(){
   // freopen("10450.txt","r",stdin);
int t;fib();
cin>>t;int c=0;
while(t--){
    c++;
    int a;
    cin>>a;
    printf("Scenario #%d:\n%lld\n\n",c,ar[a]);
}

return 0;
}
