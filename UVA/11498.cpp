#include <bits/stdc++.h>
using namespace std;

int main(){
int a;
while(cin>>a){
  if(!a)  break;
  int cx,cy;  cin>>cx>>cy;
  while(a--){
    int x,y;  cin>>x>>y;
    if(cx==x || cy==y)
      cout<<"divisa";
    else{
      if(x>cx && y>cy)  cout<<"NE";
    else  if(x<cx && y>cy)  cout<<"NO";
    else  if(x<cx && y<cy) cout<<"SO";
    else if(x>cx && y<cy) cout<<"SE";
    }
    cout<<endl;
  }
}


return 0;
}
