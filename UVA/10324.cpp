#include <bits/stdc++.h>
using namespace std;
int main(){
 // freopen("10324.txt","r",stdin);
  string s;
  int cs=1;
while(cin>>s){
  int n;cin>>n;
  cout<<"Case "<<cs++<<":"<<endl;
  while(n--){
    int a,b,i;cin>>a>>b;
    if(b<a) swap(a,b);
    int flag=1;
    if(a==b) cout<<"Yes\n";
    else {
        for( i=a;i<b;i++)
      if(s[i]!=s[i+1]){
        flag =0;
        break;
      }
      if(flag)
        cout<<"Yes\n";
      else cout<<"No\n";
  }
  }
}

return 0;
}
