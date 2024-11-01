#include <bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
    int m;
cin>>m;
  m*=567; m/=9; m+=7492;  m *=235; m/=47;  m-=498;
  if(m<0) m = -m;
  m = m%100;
  m/=10;
cout<<m<<endl;
}

return 0;
}
