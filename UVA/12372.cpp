#include <bits/stdc++.h>
using namespace std;

int main(){
int tc;
cin>>tc;
for(int i=1;i<=tc;i++){
  int a,b,c;
  cin>>a>>b>>c;
  if(a>20 || b>20 || c>20)
    cout<<"Case "<<i<<": bad"<<endl;
  else cout<<"Case "<<i<<": good"<<endl;
}

return 0;
}
