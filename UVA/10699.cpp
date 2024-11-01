#include <cstdio>

#include <set>
using namespace std;

#define mx 1000005
int ar[mx];

void sieve(){

  for(int i = 2; i<mx; i+=2)
  ar[i] = 2;

  for(int i = 3; i*i<=mx; i+=2){
    if(!ar[i]){

      for(int j = i*i; j<mx; j+=2*i){
        ar[j] = i;
      }
    }
  }

}

int factor(int n){
  set<int> s;

  while(true){

    if(ar[n])   s.insert(ar[n]);
    else s.insert(n);

    if(!ar[n]  )  break;
    n/=ar[n];
  }
/*
  for(auto i:s)
    cout<<i<<" ";
    cout<<endl;
*/
  return s.size();
}

int main(int argc, char const *argv[]) {


sieve();
  int n;


while(scanf("%d",&n )==1){
      if(!n)  break;

      printf("%d : %d\n",n,factor(n));


  }

  return 0;
}
