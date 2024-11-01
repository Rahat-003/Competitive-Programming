
#include <bits/stdc++.h>
using namespace std;



int main(){

int a,b;
int tc = 0;
while(cin>>a>>b){
  if(!a && !b)  break;
  int i;
  bool fl = false;
  for( i=0;i<=26;i++){
    if( b+b*i>=a ){
      fl  = true;
      break;
    }
  }
  printf("Case %d: ",++tc);

  if(fl)  cout<<i<<endl;
  else puts("impossible");

}

return 0;
}
