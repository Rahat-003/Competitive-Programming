#include <iostream>
using namespace std;

int f(int n,int p,int m){

    if(p==0)  return 1;
    if(p==1)  return n%m;

    if(p&1){
      int y = f(n,p-1,m);
      int x = ((y%m)*(n%m))%m;
      return x;
    }
    else{
      int x = f(n,p/2,m);
      int y = (x%m)*(x%m);
      return y%m;
    }


}

int main(int argc, char const *argv[]) {

  int n,p,m;

while(cin>>n>>p>>m){

      int ans = f(n,p,m);
      cout<<ans<<endl;


  }

  return 0;
}
