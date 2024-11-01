#include <bits/stdc++.h>
using namespace std;


int digit(int a){
  int c=0;
  while(a){
    c+= a%10;
      a/=10;
  }
  if(c>=10)
   return digit(c);

  return c;
}
int main(){
int a;
while(cin>>a)
cout<<digit(a)<<endl;

return 0;
}
