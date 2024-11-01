#include <bits/stdc++.h>
using namespace std;

int ar[100000000/32];
bool check(int n,int id){
  return n&(1<<id);
}

int Set(int n,int id) {
    return n|=(1<<id);
}
int prime[10000000];
void bSieve(int n){

    for ( size_t i = 3; i*i <= n; i+=2 ) {
      /* code */
      if ( !check(ar[i/32],i&31 )) {
        /* code */
        for (size_t j = i*i; j <= n; j+= 2*i) {
          /* code */
          ar[j/32] = Set(ar[j/32],j&31);
        }
      }
    }

int id = 0;
prime[id] = 2;

for(int i = 3;i<=n;i+=2)

  if (!check(ar[i/32],i&31)) {
    /* code */
    prime[++id] = i;
  }

}

int main() {
int n;
cin>>n;
bSieve(n);
int i;
for(i = 0; prime[i]<=n && prime[i]; i++){
  cout<<prime[i]<<" ";
  // if(!prime[i]) break;
}

puts("");
cout<<i<<endl;
  return 0;
}
