#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

bool check( int num, int id ){
  return num&(1<<id);
}


int Set(int num, int id){
  num|= (1<<id);
  return num;
}

void bitWiseSieve(){

  for(int i = 3; i*i<=n; i+=2){

    if( !check(v[i/32],i%32) ){

      for(int j = i*i; j<=n; j+=2*i ){
        v[j/32] = Set( v[j/32],j%32 );

      }
    }
  }

}

int main(){

cin>>n;

v.assign(n/32+2,0);

bitWiseSieve();

cout<<2<<" ";

int cnt = 1;

for(int i = 3;i<=n; i+=2)
  if(check(v[i/32], i%32)==0){
    cout<<i<<" ";
    cnt++;
  }

cout<<endl<<cnt<<endl;




return 0;
}
