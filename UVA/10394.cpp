
#include <cstdio>
using namespace std;

#define mx 20000000

struct node{
  int a,b;
  node(int x = 0,int y = 0){
    a = x;
    b = y;
  }
};


bool ar[mx+2];
node prime[mx/2];

void sieve(){

  ar[0] = ar[1] = 1;
  for(int i = 3; i*i<=mx; i+=2){
    if(!ar[i]){
      for(int j = i*i; j<mx; j+=2*i)
        ar[j] = true;
    }
  }
  int y = 3;
  int id = 0;

  for(int i = 5; i<mx; i+=2){
    if(!ar[i] && i-y==2){
      prime[++id] = node(y,i);
    }
    if(!ar[i])  y = i;
  }



}


int main(int argc, char const *argv[]) {

sieve();
int i;
while(scanf("%d",&i)==1)

    printf("(%d, %d)\n",prime[i].a,prime[i].b);

  return 0;
}
