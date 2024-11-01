#include <iostream>
using namespace std;
int main(){
 // freopen("10963.txt","r",stdin);
  int tc;
  cin>>tc;
  int c=0;
  while(tc--){
      if(c>0) cout<<endl;
  c++;
    int a;  cin>>a;
    int total=0;
    for(int i=0;i<a;i++){
      int b,c;
      cin>>b>>c;
      total+= b-c;
    }
    if(total==a) cout<<"yes\n";
    else cout<<"no\n";
  }



return 0;
}
