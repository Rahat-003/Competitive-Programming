#include <bits/stdc++.h>
using namespace std;
int b,p,m;

int bg_no_mod(int b,int p){
  if(p==0)  return 1;
  if(p==1)  return b;
  if(p%2==0){
    int a = bg_no_mod(b,p/2);
    return ((a%m)*(a%m)) %m;
  }
  else{
    int c = bg_no_mod(b,p-1);
    return ((c%m)*(b%m))%m;
  }

}


int main(){

while(cin>>b>>p>>m){
  int ans = bg_no_mod(b,p);
  cout<<ans<<endl;
}





return 0;
}
