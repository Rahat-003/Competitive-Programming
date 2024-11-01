#include <bits/stdc++.h>
using namespace std;
#define MAX 10003
vector<bool> v(MAX,true);
void sieve(){
  v[0] = v[1]= false;

  for(int i=4;i<v.size();i+=2)
    v[i]= false;
  for(int i=3;i*i<=MAX;i+=2){
      if(v[i]){
        for(int j=2*i; j<=MAX; j+=i){
      v[j] = false;
      }
      }
  }
}
int digit(int a){
  for(int i=a;i>=2;i--)
    if(v[i] && a%i==0)
    return i;

}
int b,cnt=0;
void dd(int a){
  int total;
      if(total == b)
      cout<<cnt;
    if(total>b){
    cnt=0;
    total=a;
    }
    cnt++;
    total += digit(total);


}


int main(){

int tc=0;
int a;
sieve();

while(cin>>a>>b){
  dd(a);


}




return 0;
}
