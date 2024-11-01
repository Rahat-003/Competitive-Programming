#include <bits/stdc++.h>
using namespace std;



int main(){
double a,b,c;
while(cin>>a>>b>>c){
    if(!a && !b && !c)  break;
  if(a<b)
    swap(a,b);
  if(c<a)
    swap(c,a);
  if(c*c==a*a + b*b)
    cout<<"right"<<endl;
  else cout<<"wrong"<<endl;
}




return 0;
}
