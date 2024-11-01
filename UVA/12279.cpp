#include <bits/stdc++.h>
using namespace std;

int main(){
int tc = 0;
int a;
while(cin>>a){
  if(!a)  break;
  tc++;
  int total=0;
  for(int i=0,b;i<a;i++){
    cin>>b;
    if(b>0 && b<=99)  total+=1;
    if(b==0)  total-=1;
  }
  printf("Case %d: %d\n",tc,total);
}



return 0;
}
