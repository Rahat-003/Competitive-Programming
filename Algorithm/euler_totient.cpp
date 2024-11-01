#include <iostream>
using namespace std;

#define mx 5000003
#define mxx 11
typedef long long ll;
int phi[mx];

long long ans[mx];

void totient(){
  for(int i = 0;i<mx;i++){
    phi[i] = i;
    if(!(i&1))
      phi[i]/=2;
  }
    for(int i = 3;i<mx;i++){
      if(phi[i]==i){
      --phi[i];
      for(int j = 2*i; j<mx; j+=i){
        phi[j]-=phi[j]/i;
      }
    }
}

  for(int i=1;i<mx;i++)
    for(int j=i+i;j<mx;j+=i)
      ans[j]+=(ll)phi[j/i]*i;

      for(int i=1;i<mx;i++)
        ans[i]+=ans[i-1];
/*
*/
}


int main() {

totient();
/*
for (size_t i = 1; i <mxx; i++) {
  printf("%lld ",ans[i]);
//vector<int> v;
}
*/
int n;
while(scanf("%lld",&n)==1)
    printf("%lld\n",ans[n]);



return 0;
}
