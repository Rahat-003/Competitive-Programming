#include <bits/stdc++.h>
using namespace std;


int main(){
int t;
cin>>t;
int tc = 0;
while(t--){
  int a,b,c;
  cin>>a>>b>>c;
  int ans = (b+c)%a;
  if(!ans)  ans+=a;

  printf("Case %d: %d\n",++tc,ans);
}






return 0;
}
