#include <bits/stdc++.h>
using namespace std;
int main(){ //freopen("11661.txt","r",stdin);
int n;
while(cin>>n){
  if(n==0) break;
  string s;
  cin>>s;
  int f1=0,p1=2000003,p2=2000003*2,dif=2000003;
  for(int i=0;i<n;i++){
    if(s[i]=='Z'){
        f1=1;
        break;
    }
  if(s[i]=='R'){
    p1=i;
  }
    if(s[i]=='D'){
      p2=i;
    }

  if(abs(p1-p2)<dif) dif=abs(p1-p2);

  }
  if(f1==1) cout<<0<<endl;
  else cout<<dif<<endl;

}


return 0;
}
