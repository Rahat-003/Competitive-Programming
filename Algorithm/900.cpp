#include <iostream>
using namespace std;
#define ll long long

ll ar[100];
void fib(){
    ll a=0,b=1,c;
    ar[0]=0;ar[1]=1;
    for(ll i=2;i<=51;i++){
        c=a+b;
        a=b;
        b=c;
        ar[i]=b;
    }
}
int main(){
ll n;
fib();
while(cin>>n)
  {   if(n==0)break;
      cout<<ar[n+1]<<endl;
  }

}
